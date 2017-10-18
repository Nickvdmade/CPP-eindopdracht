#include "FileReader.h"
#include <string>
#include <iostream>

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

char * FileReader::ReadFile(char* fileName)
{
	ifstream file(fileName);
	if (file)
	{
		int length = count(istreambuf_iterator<char>(file), istreambuf_iterator<char>(), '\n');
		file.seekg(0, file.beg);
		string text;
		for (int i = 0; i < length; i++)
		{
			string str;
			getline(file, str);
			text.append(str + '\n');
		}
		char* result = new char[text.length()];
		for (int i = 0; i < text.length(); i++)
			result[i] = text[i];
		result[text.length()] = '\0';
		cout << result << endl;
		//file.read(value, length);
		file.close();
		return result;
	}
	char* result = "Could not open file.";
	return result;
}
