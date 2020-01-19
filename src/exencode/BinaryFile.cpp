#include <exencode/exencode.h>
#include <base64.h>
#include <iostream>
#include <fstream>
#include <sys/types.h> 
#include <sys/stat.h>
#include <regex>

BinaryFile::BinaryFile() {}

BinaryFile::BinaryFile(const std::string fileName)
{

	BinaryFile::fileName = fileName;
	BinaryFile::size = getFileSize();
	
	readFromEncoded();
	//readFromBinary();
}


void BinaryFile::readFromBinary()
{
	char* buffer = new char[size];
	std::ifstream file(fileName, std::ios::in | std::ios::binary);
	file.read(buffer, size);
	binaryData = base64::base64_encode((unsigned const char*)buffer, size);
}

void BinaryFile::readFromEncoded() {

	
	std::string str;
	std::string acc;
	std::regex e("(^.*\\{|\"|,|\\}.*)");

	std::ifstream file(fileName);

	while (std::getline(file, str))
	{
		acc += std::regex_replace(str, e, "");
	}

	encodedData = acc;
	file.close();

	dumpToBinary();
}


long BinaryFile::getFileSize()
{
	struct stat stat_buf;
	int rc = stat(fileName.c_str(), &stat_buf);
	return rc == 0 ? stat_buf.st_size : -1;
}

void BinaryFile::dumpToBinary() {
	dumpToBinary(fileName + ".dec");
}

void BinaryFile::dumpToBinary(std::string path) {
	
	std::string dec = base64::base64_decode(encodedData);
	char* cstr = new char[size];
	std::copy(dec.begin(), dec.end(), cstr);
	cstr[dec.size()] = '\0';

	std::ofstream file(path, std::ios::out | std::ios::binary);
	file.write((const char*)cstr, size);
	file.close();

}

void BinaryFile::dumpToEncodedStr(std::string path, std::string identifier) {

	std::string formatted;	
	for (const auto& l : splitData()) formatted += "\"" + l + "\",\n";	
	formatted = "std::string " + identifier + " []={\n" + formatted + "};";

	std::ofstream file;
	file.open(path);
	file << formatted;
	file.close();
}

//auto y2 = base64::base64_decode(y);


std::vector<std::string> BinaryFile::splitData() {

	std::vector<std::string> result;
	int blockSize(1600);
	int index = 0;
	while (true) {
		try {
			// Take the next section of size blockSize
			result.push_back(encodedData.substr(index, blockSize));
		}
		catch (const std::exception & e) {
			// We have reached end of data
			if (index < encodedData.length()) {
				result.push_back(encodedData.substr(index));
			}
			break;
		}
		index += blockSize;
	}

	std::string recon;
	for (const auto& l : result) recon += l;
	if (recon.compare(encodedData) != 0) {
		throw std::runtime_error("Encoded data mismatch! Aborting.");
	}

	return result;
}