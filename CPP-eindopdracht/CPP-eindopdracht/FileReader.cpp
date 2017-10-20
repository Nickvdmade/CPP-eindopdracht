#include "FileReader.h"

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

char** FileReader::readFile(char* fileName)
{
	ifstream file(fileName);
	if (file)
	{
		int entersFound = count(istreambuf_iterator<char>(file), istreambuf_iterator<char>(), '\n');
		file.seekg(0, file.beg);
		char** result = new char*[entersFound + 1];
		result[0] = new char[1];
		result[0][0] = entersFound;
		result[0][1] = '\0';
		int length = 50;
		result[1] = new char[length];
		int i = 1;
		int j = 0;
		for (char c = file.get(); i != entersFound + 1; c = file.get(), j++)
		{
			if (c == '\n')
			{
				result[i][j] = '\0';
				i++;
				length = 50;
				result[i] = new char[length];
				j = -1;
			}
			else
			{
				if (j >= length)
				{
					length += 50;
					result[i] = static_cast<char*>(realloc(result[i], length * sizeof(char)));
				}
				result[i][j] = c;
			}
		}
		j--;
		result[i][j] = '\0';
		file.close();
		return result;
	}
	char* result = "Could not open file.";
	return &result;
}
