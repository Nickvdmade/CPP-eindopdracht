#include <iostream>
#include "RandomGenerator.h"
#include "FileReader.h"
#include "Ships.h"

using namespace std;

void main()
{
	Ships* ships = new Ships();

	//RandomGenerator randomGenerator;

	////voorbeeld 1
	//cout << "Random getallen van 1 t/m 6: ";
	//for (int i = 0; i < 10; ++i)
	//{
	//	cout << randomGenerator.GetRandomNumber(1, 6) << ", ";
	//}
	//cout << endl;

	////voorbeeld 2
	//cout << "Random getallen van 20 t/m 100: ";
	//for (int i = 0; i < 10; ++i)
	//{
	//	cout << randomGenerator.GetRandomNumber(20, 100) << ", ";
	//}
	//cout << endl;

	getchar();

	_CrtCheckMemory();
}