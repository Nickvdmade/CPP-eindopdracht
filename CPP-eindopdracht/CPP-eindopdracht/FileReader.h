#pragma once

#include <fstream>

using namespace std;

class FileReader
{
public:
	FileReader();
	~FileReader();
	static char** readFile(char* fileName);
};
