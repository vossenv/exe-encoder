#pragma once


#include <string>
class base64
{
	//
//  base64 encoding and decoding with C++.
//  Version: 1.01.00
//


public:
	static std::string base64_encode(unsigned char const*, unsigned int len);
	static std::string base64_decode(std::string const& s);



};

