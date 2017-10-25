#pragma once
#include "Ship.h"
#include "Inventory.h"

class Player
{
public:
	explicit Player(Ship* ship, Location* location);
	~Player();
	char* BuyGoods(char* name, int amount) const;
	char* SellGoods(char* name, int amount) const;
	char* BuyCannons(int type, int amount) const;
	char* SellCannons(int type, int amount) const;
	char* BuyShip(char* name) const;
	void ShowAvailableGoods() const;
	void ShowAvailableShips() const;
	void ShowAvailableCannons() const;
	void ShowLocations() const;
	char* Depart(char* destination);
	int Repair() const;

	void ShowInfo() const;

private:
	char* destination_;
	int distance_;
	Location* location_;
	Ship* ship_;
	Inventory* inventory_;
};
