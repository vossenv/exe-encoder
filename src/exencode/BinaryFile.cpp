#include <base64.h>
#include <exencode/exencode.h>
#include <fstream>
#include <iostream>
#include <regex>
#include <sys/stat.h>
#include <sys/types.h>



BinaryFile::BinaryFile(const std::string& FileName, DataType ContentType)
{
	fileName = FileName;
	contentType = ContentType;
	fileSize = getFileSize();
	defaultIdentifier = "default_identifier";

	if (ContentType == DataType::Binary) {
		readFromBinary();
	} else {
		readFromEncoded();
}
}

void BinaryFile::readFromBinary()
{
	auto buffer = new char[fileSize];
	std::ifstream file(fileName, std::ios::in | std::ios::binary);
	file.read(buffer, fileSize);
	encodedData = base64::base64_encode(reinterpret_cast<unsigned const char*>(buffer), fileSize);
}

void BinaryFile::readFromEncoded()
{
	std::string str;
	std::string acc;
	std::regex e(R"((^.*\{|"|,|\}.*))");
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

void BinaryFile::dumpToBinary() const { dumpToBinary(fileName + ".dec"); }


void BinaryFile::dumpToRawEncodedStr() const
{
	dumpToRawEncodedStr(fileName + ".raw");
}

void BinaryFile::dumpToBinary(const std::string& Path) const
{
	auto dec = base64::base64_decode(encodedData);
	std::cout << dec;
	auto cstr = new char[fileSize];
	std::copy(dec.begin(), dec.end(), cstr);
	cstr[dec.size()] = '\0';

	std::ofstream file(Path, std::ios::out | std::ios::binary);
	file.write(static_cast<const char*>(cstr), fileSize);

	file.close();
}


void BinaryFile::dumpToEncodedStr() const
{
	dumpToEncodedStr(fileName + ".enc", defaultIdentifier);
}

void BinaryFile::dumpToEncodedStr(const std::string& Path, const std::string& Identifier) const
{
	std::string formatted;
	for (const auto& l : splitData()) {
		formatted += "\"" + l + "\",\n";
}
	formatted = "std::string " + Identifier + " []={\n" + formatted + "};";

	std::ofstream file;
	file.open(Path);
	file << formatted;
	file.close();
}

void BinaryFile::dumpToRawEncodedStr(const std::string& Path) const
{
	std::ofstream file;
	file.open(Path);
	file << encodedData;
	file.close();
}

auto BinaryFile::splitData() const -> std::vector<std::string>
{
	std::vector<std::string> result;
	auto blockSize(1600);
	auto index = 0;
	while (true)
	{
		try
		{
			// Take the next section of size blockSize
			result.push_back(encodedData.substr(index, blockSize));
		}
		catch (const std::exception& e)
		{
			// We have reached end of data
			if (index < encodedData.length())
			{
				result.push_back(encodedData.substr(index));
			}
			break;
		}
		index += blockSize;
	}

	std::string recon;
	for (const auto& l : result) {
		recon += l;
}
	if (recon != encodedData)
	{
		throw std::runtime_error("Encoded data mismatch! Aborting.");
	}

	return result;
}

auto BinaryFile::getFileSize() const -> long
{
	struct stat stat_buf{};
	auto rc = stat(fileName.c_str(), &stat_buf);
	return rc == 0 ? stat_buf.st_size : -1;
}
