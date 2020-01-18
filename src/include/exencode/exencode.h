#pragma once
#include <iostream>

class Storage {
public:
	bool fileExists(const std::string filename);
	void readBinaryData(const std::string filename);

};
