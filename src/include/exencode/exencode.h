#pragma once
#include <iostream>
#include <vector>



enum class dataType { BINARY, TEXT };

class ErrorHandler {
public:
	static void terminator();
	static void handle(const std::exception& e);
};


class Converter {
public:
	bool fileExists(const std::string filename);
	void convertFile(const std::string filename);

	//Converter();

};

class BinaryFile {
public:	
	
	std::string fileName;
	std::string encodedData;
	BinaryFile::dataType contentType = dataType::BINARY;
	long fileSize = 0;
	void readFromBinary();
	void readFromEncoded();
	void dumpToBinary();
	void dumpToBinary(std::string path);
	void dumpToEncodedStr();
	void dumpToEncodedStr(std::string path, std::string identifier);
	void dumpToRawEncodedStr(std::string path);
	void dumpToRawEncodedStr();
	long getFileSize();
	std::vector<std::string> splitData();

	BinaryFile(const std::string & fileName, dataType contentType = dataType::BINARY);
	BinaryFile();

};

class Util {

public:
	static std::vector<std::string> split(const std::string str, const std::string delims);

};
