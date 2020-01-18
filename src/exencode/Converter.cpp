#include <exencode/exencode.h>
#include <base64.h>
#include <iostream>
#include <fstream>

//#include <sstream>
//#include <algorithm>
//#include <iterator>
//#include <sys/stat.h>

//#include <math.h> 
//#include <string>
//#include <stdexcept>
//#include "prtk.txt"

char* getChar(int size) {
	char* buffer = new char[size];
	return buffer;
}

char* strToChar(const std::string s) {
	char* cstr = getChar(s.size());
	std::copy(s.begin(), s.end(), cstr);
	cstr[s.size()] = '\0';
	return cstr;
}

bool Storage::fileExists(const std::string filename)
{
	std::ifstream ifile(filename);
	return ifile.good();
}

void Storage::readBinaryData(const std::string filename)
{

	if (!fileExists(filename)) {
		throw std::exception(strToChar("File not found: " + filename));
	}

	std::ifstream file(filename, std::ios::in | std::ios::binary);
	char* buffer = getChar(3463096);
	file.read(buffer, 3463096);

	auto y = base64::base64_encode((unsigned const char*)buffer, 3463096);

	auto y2 = base64::base64_decode(y);
	//writef("prtk.txt", y);

	auto r = buffer[2];

	std::cout << "";

}