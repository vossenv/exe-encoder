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


#ifdef ISWINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

std::string get_current_dir() {
	char buff[FILENAME_MAX]; //create string buffer to hold path
	auto v = GetCurrentDir(buff, FILENAME_MAX);
	std::string current_working_dir(buff);
	return current_working_dir;
}

//char* getChar(int size) {
//	char* buffer = new char[size];
//	return buffer;
//}
//
//char* strToChar(const std::string s) {
//	char* cstr = getChar(s.size());
//	std::copy(s.begin(), s.end(), cstr);
//	cstr[s.size()] = '\0';
//	return cstr;
//}



bool Converter::fileExists(const std::string filename)
{
	std::ifstream ifile(filename);
	return ifile.good();
}






void Converter::convertFile(const std::string filename) {

	if (!fileExists(filename)) {
		throw std::runtime_error("File not found: " + filename);
	}

	BinaryFile file(filename);


	//file.dumpToEncodedStr("test.txt", "varx");

	//file.dumpToBinary();

	//file.dumpToBinary("test.jpg");

	std::cout << "";
	
	//b.data = "X";

}