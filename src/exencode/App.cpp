
#include <iostream>
#include <exencode/exencode.h>
#include <CLI11.hpp>




int main()
{
	std::set_terminate(ErrorHandler::terminator);


	std::string str = "abc|1$23|xyz|789";
	std::string delims = " |.;?";

	auto y = Util::split(str, "$");



	Converter conv;

	//conv.convertFile("../../src/test/test-image.jpg");
	//conv.convertFile("../../src/test/enc.txt");

	std::string x = "b/\n";

	//auto z = Util::split("a*/b*\\c", x);

	std::cout << "";
}
