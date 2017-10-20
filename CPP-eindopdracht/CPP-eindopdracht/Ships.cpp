#include "Ships.h"
#include "FileReader.h"

Ships::Ships()
{
	char** shipsInfo = FileReader::readFile("Files/schepen.csv");
	int size = shipsInfo[0][0];
	ships = new Ship*[size];
	for (int i = 1; i < size; i++)
	{
		ships[i - 1] = new Ship(shipsInfo[i + 1]);
	}
}

Ships::~Ships()
{
	for (int i = 0; i < sizeof(ships); i++)
		delete ships[i];
	delete ships;
}
