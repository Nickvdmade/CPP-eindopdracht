#pragma once

#include <fstream>

using namespace std;

class FileReader
{
public:
	FileReader();
	~FileReader();
	char* ReadFile(char* fileName);
};
