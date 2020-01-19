#pragma once
#include <iostream>
#include <vector>

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
	std::string binaryData;
	long size = 0;
	void readFromBinary();
	void readFromEncoded();
	void dumpToBinary();
	void dumpToBinary(std::string path);
	void dumpToEncodedStr(std::string path, std::string identifier);
	long getFileSize();
	std::vector<std::string> splitData();

	BinaryFile(const std::string fileName);
	BinaryFile();

};
