#pragma once
#include <fstream>

class Reader
{
private:

	std::fstream file;
	char* buffer[256];

};