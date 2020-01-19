

#include <iostream>
#include <exencode/exencode.h>
#include <CLI11.hpp>

#ifndef PLATFORM
#define PLATFORM "NO SYSTEM NAME"
#endif

int main()
{
	std::set_terminate(ErrorHandler::terminator);

	Converter conv;

	//conv.convertFile("../../src/test/test-image.jpg");
	conv.convertFile("../../src/test/enc.txt");


	std::cout << "";
}
