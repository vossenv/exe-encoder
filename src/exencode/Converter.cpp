#include <base64.h>
#include <exencode/exencode.h>
#include <fstream>
#include <iostream>

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
#define GET_CURRENT_DIR _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

std::string get_current_dir() {
  char buff[FILENAME_MAX]; // create string buffer to hold path
  auto v = GET_CURRENT_DIR(buff, FILENAME_MAX);
  std::string current_working_dir(buff);
  return current_working_dir;
}

// char* getChar(int size) {
//	char* buffer = new char[size];
//	return buffer;
//}
//
// char* strToChar(const std::string s) {
//	char* cstr = getChar(s.size());
//	std::copy(s.begin(), s.end(), cstr);
//	cstr[s.size()] = '\0';
//	return cstr;
//}

bool Converter::fileExists(const std::string& Filename) {
  std::ifstream ifile(Filename);
  return ifile.good();
}

void Converter::convertFile(const std::string& Filename) {

  if (!fileExists(Filename)) {
    throw std::runtime_error("File not found: " + Filename);
  }

  BinaryFile File(Filename);

  // file.dumpToEncodedStr("test.txt", "varx");

  // file.dumpToBinary();

  // file.dumpToBinary("test.jpg");

  std::cout << "";

  // b.data = "X";
}
