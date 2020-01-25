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
	bool fileExists(std::string filename);
	void convertFile(std::string filename);

	//Converter();

};

class BinaryFile {
public:	
	
	std::string fileName;
	std::string encodedData;
	dataType contentType = dataType::BINARY;
	long fileSize = 0;
	void readFromBinary();
	void readFromEncoded();
	void dumpToBinary();
	void dumpToBinary(const std::string& path);
	void dumpToEncodedStr();
	void dumpToEncodedStr(const std::string& path, const std::string& identifier);
	void dumpToRawEncodedStr(const std::string& path);
	void dumpToRawEncodedStr();
	long getFileSize();
	std::vector<std::string> splitData();

	explicit BinaryFile(const std::string & fileName, dataType contentType = dataType::BINARY);
	BinaryFile();

};

class Util {

public:
	static std::vector<std::string> split(std::string str, std::string delims);

};
