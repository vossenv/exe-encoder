

#include <iostream>
#include <exencode/exencode.h>
#include <CLI11.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>

#ifndef PLATFORM
#define PLATFORM "NO SYSTEM NAME"
#endif

int main(int argc, char** argv)
{

	bool stream = false;
	bool provOnly = false;
	bool eulaSuppress;
	bool regSuppress;
	std::string keyFilename, locales, provFolder;
	std::vector<std::string> cliKeys;
	std::set_terminate(ErrorHandler::terminator);

	CLI::App app{ "Binary converter" };

	auto serialize_cmd = app.add_subcommand("serialize", "Use to apply a serial key.  You can apply this using a comma separated list of keys as an argument, \
or by pointing to a file containing the keys.");
	serialize_cmd->add_option("-k,--key", cliKeys, "A single key or list of keys to target. Usage: --key 1111-XXXX-9411 1111-XXXX-...");
	serialize_cmd->add_option("--key-file", keyFilename, "Input file for serial keys. File should be single column of serial keys.")->check(CLI::ExistingFile);
	serialize_cmd->add_option("--locales", locales, "Optional; specify from the limited list of locales in the formal xx_XX or ALL. Use --locales list for a description");
	serialize_cmd->add_option("--provfile", provFolder, "Optional; path of the folder where prov.xml is created.");

	CLI11_PARSE(app, argc, argv);

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
		CLI11_PARSE(app, argc, argv);
	return 0;

}
