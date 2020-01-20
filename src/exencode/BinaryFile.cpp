#include <exencode/exencode.h>
#include <base64.h>
#include <iostream>
#include <fstream>
#include <sys/types.h> 
#include <sys/stat.h>
#include <regex>

BinaryFile::BinaryFile() {}

BinaryFile::BinaryFile(const std::string & fileName, dataType contentType)
{
	BinaryFile::fileName = fileName;
	BinaryFile::contentType = contentType;
	BinaryFile::fileSize = getFileSize();

	if (contentType == dataType::BINARY) {
		readFromBinary();
	}
	else {
		readFromEncoded();
	}
}

void BinaryFile::readFromBinary()
{
	char* buffer = new char[fileSize];
	std::ifstream file(fileName, std::ios::in | std::ios::binary);
	file.read(buffer, fileSize);
	encodedData = base64::base64_encode((unsigned const char*)buffer, fileSize);
}

void BinaryFile::readFromEncoded() {

	std::string str;
	std::string acc;
	std::regex e("(^.*\\{|\"|,|\\}.*)");
	std::regex e2("\\r");
	std::ifstream file(fileName);

	while (std::getline(file, str))
	{
		str = std::regex_replace(str, e2, "");
		acc += std::regex_replace(str, e, "");
	}

	encodedData = acc;
	file.close();
}

void BinaryFile::dumpToBinary() {
	dumpToBinary(fileName + ".dec");
}

void BinaryFile::dumpToEncodedStr() {
	dumpToEncodedStr(fileName + ".enc", "default_identifier");
}

void BinaryFile::dumpToRawEncodedStr() {
	dumpToRawEncodedStr(fileName + ".raw");
}

void BinaryFile::dumpToBinary(std::string path) {

	std::string dec = base64::base64_decode(encodedData);

	std::cout << dec;
	char* cstr = new char[fileSize];
	std::copy(dec.begin(), dec.end(), cstr);
	cstr[dec.size()] = '\0';

	std::ofstream file(path, std::ios::out | std::ios::binary);
	file.write((const char*)cstr, fileSize);
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

void BinaryFile::dumpToRawEncodedStr(std::string path) {
	std::ofstream file;
	file.open(path);
	file << encodedData;
	file.close();
}

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

long BinaryFile::getFileSize()
{
	struct stat stat_buf;
	int rc = stat(fileName.c_str(), &stat_buf);
	return rc == 0 ? stat_buf.st_size : -1;
}