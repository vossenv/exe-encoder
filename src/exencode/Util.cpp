#include <exencode/exencode.h>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

#define strtk_no_tr1_or_boost
#include <strtk/strtk.hpp>

char* getChar(int size) {
	char* buffer = new char[size];
	return buffer;
}

std::vector<std::string> Util::split(const std::string str, const std::string delims) {
	std::vector<std::string> token_list;
	strtk::split(delims, str, strtk::range_to_type_back_inserter(token_list));
	return token_list;
}


//std::vector<std::string> Util::split(const std::string& s, char delim)
//{
//	std::string token;
//	std::istringstream tokenStream(s);
//	std::vector<std::string> result;
//while (std::getline(tokenStream, token, delim))
//	{
//		result.push_back(token);
//	}
//	return result;
//}
//
//
//
//std::vector<std::string> split(std::string str, std::string delims) {
//
//	std::string r = "[" + delims + "]";
//	std::regex re(r);
//	std::sregex_token_iterator first{ str.begin(), str.end(), re, -1 }, last;
//	std::vector<std::string> tokens{ first, last };
//
//	return tokens;
//
//}
