#include <exencode/exencode.h>
#include <base64.h>
#include <iostream>
#include <fstream>


BinaryFile::BinaryFile() {}

BinaryFile::BinaryFile(const std::string fileName)
{

	BinaryFile::fileName = fileName;
	BinaryFile::size = getFileSize();
	read();
}


void BinaryFile::read()
{
	char* buffer = new char[size];
	std::ifstream file(fileName, std::ios::in | std::ios::binary);
	file.read(buffer, size);
	data = base64::base64_encode((unsigned const char*)buffer, size);
}

long BinaryFile::getFileSize()
{
	struct stat stat_buf;
	int rc = stat(fileName.c_str(), &stat_buf);
	return rc == 0 ? stat_buf.st_size : -1;
}

void BinaryFile::dumpBinary(std::string path) {

	std::ofstream file;
	file.open(path);
	file << base64::base64_decode(data);
	file.close();


}

//auto y2 = base64::base64_decode(y);