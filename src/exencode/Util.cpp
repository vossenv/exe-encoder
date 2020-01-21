#include <exencode/exencode.h>
#include <sstream>
#include <string>
#include <cstring>

char* getChar(int size) {
	char* buffer = new char[size];
	return buffer;
}

std::vector<std::string> _split(const std::string& s, char delim)
{
	std::string token;
	std::istringstream tokenStream(s);
	std::vector<std::string> result;
	while (std::getline(tokenStream, token, delim))
	{
		result.push_back(token);
	}
	return result;
}


std::vector<std::string> Util::split(const std::string& s, std::string delims) {

	char* cstr = getChar(delims.size() + 1);
	strcpy(cstr, delims.c_str());

	for (int i = 0; i < delims.size(); ++i)
	{
		std::cout << "|" <<  cstr[i] << "|" ;
	}

	return _split("a", 'x');
}



std::vector<std::string> Util::split(const std::string& s, char delim)
{
	std::string token;
	std::istringstream tokenStream(s);
	std::vector<std::string> result;
while (std::getline(tokenStream, token, delim))
	{
		result.push_back(token);
	}
	return result;
}




