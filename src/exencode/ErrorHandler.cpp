#include <exencode/exencode.h>
#include <iostream>

void ErrorHandler::terminator()
{
	if (std::exception_ptr exc = std::current_exception()) {
		try {
			std::rethrow_exception(exc);
		}
		catch (const std::exception & e) {
			ErrorHandler::handle(e);
		}
	}

	exit(0);
}

void ErrorHandler::handle(const std::exception& e)
{
	auto errorType = typeid(e).name();
	std::cout << "Unhandled exception: " << errorType << ": " << e.what() << '\n';
	exit(1);
}




