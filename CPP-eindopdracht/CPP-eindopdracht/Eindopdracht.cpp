#include <iostream>
#include "RandomGenerator.h"
#include "Ships.h"
#include "Ports.h"
#include "Location.h"
#include "Player.h"

using namespace std;

void main()
{

	Ships* ships = new Ships();
	Ports* ports = new Ports();
	Location* startLocation = new Location(ports, ships, "Roatan");
	Player* player = new Player(ships->GetShip(0), startLocation);
	player->ShowInfo();

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

	delete ships;
	delete ports;
	delete startLocation;
	delete player;

	_CrtDumpMemoryLeaks();
}