#pragma once
#include <iostream>

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
	std::string data;
	long size = 0;
	void read();
	void dumpBinary(std::string path);
	long getFileSize();

	BinaryFile(const std::string fileName);
	BinaryFile();

};