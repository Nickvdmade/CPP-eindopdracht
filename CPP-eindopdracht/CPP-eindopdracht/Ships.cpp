#include "Ships.h"

Ships::Ships()
{
	ships_ = new Ship*[13];
	ships_[0] = new Ship("Pinnace", 10000, 200, 8, 100, true, 0);
	ships_[1] = new Ship("Sloep", 19000, 200, 14, 110, true, 0);
	ships_[2] = new Ship("Brigg", 27000, 250, 16, 140, true, 0);
	ships_[3] = new Ship("Barque", 36000, 250, 20, 150, true, 0);
	ships_[4] = new Ship("Korvet", 60000, 350, 24, 200, false, 0);
	ships_[5] = new Ship("Fluyt", 40000, 500, 16, 220, false, 1);
	ships_[6] = new Ship("Fregat", 70000, 400, 26, 220, false, 1);
	ships_[7] = new Ship("Galjoen", 120000, 600, 36, 280, false, 1);
	ships_[8] = new Ship("Handelsfluyt", 50000, 800, 8, 300, false, 2);
	ships_[9] = new Ship("Caravel", 160000, 500, 40, 300, false, 2);
	ships_[10] = new Ship("Carrack", 140000, 550, 40, 320, false, 2);
	ships_[11] = new Ship("Oorlogsgaljoen", 180000, 400, 46, 320, false, 2);
	ships_[12] = new Ship("Ship of the Line", 200000, 400, 50, 340, false, 2);
}

Ships::~Ships()
{
	for (int i = 0; i < sizeof(ships_); i++)
		delete ships_[i];
	delete ships_;
}
