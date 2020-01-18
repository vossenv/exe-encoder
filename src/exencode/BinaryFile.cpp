#include <exencode/exencode.h>
#include <base64.h>
#include <iostream>
#include <fstream>

//char* strToChar(const std::string s) {
//	char* cstr = new char[size];
//	std::copy(s.begin(), s.end(), cstr);
//	cstr[s.size()] = '\0';
//	return cstr;
//}

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

	std::ofstream file(path, std::ios::out | std::ios::binary);
	std::string dec = base64::base64_decode(data);

	char* cstr = new char[size];
	std::copy(dec.begin(), dec.end(), cstr);
	cstr[dec.size()] = '\0';
	file.write((const char *) cstr, size);
	   
}

//auto y2 = base64::base64_decode(y);