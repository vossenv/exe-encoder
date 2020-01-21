

#include <iostream>
#include <exencode/exencode.h>
#include <CLI11.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>

#ifndef PLATFORM
#define PLATFORM "NO SYSTEM NAME"
#endif

int main()
{
	
	
	std::string input("geeks\tfor\tgeeks");
	std::vector<std::string> result;
	boost::split(result, input, boost::is_any_of("\t"));

	std::set_terminate(ErrorHandler::terminator);

	Converter conv;

	//conv.convertFile("../../src/test/test-image.jpg");
	//conv.convertFile("../../src/test/enc.txt");

	std::string x = "b/\n";

	auto z = Util::split("a*/b*\\c", x);

	std::cout << "";


}
