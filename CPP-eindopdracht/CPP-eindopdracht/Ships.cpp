#include "Ships.h"
#include "FileReader.h"

Ships::Ships()
{
	FileReader fileReader;
	char* shipsInfo = fileReader.ReadFile("Files/schepen.csv");
	char* shipInfo = new char[256];
	char c = shipsInfo[0];
	for (int i = 0; c != '\0'; i++)
	{
		c = shipsInfo[i];
		if (c == '\0')
			break;
		int j;
		for (j = 0; c != '\n'; j++)
		{
			c = shipsInfo[i];
			shipInfo[j] = c;
			i++;
		}
		i--;
		shipInfo[j - 1] = '\0';
	}
}

Ships::~Ships()
{
	for (int i = 0; i < sizeof(ships); i++)
		delete ships[i];
	delete ships;
}
