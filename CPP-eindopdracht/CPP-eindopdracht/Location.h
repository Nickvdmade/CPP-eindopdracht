#pragma once
#include "Ports.h"
#include "Ship.h"

class Ships;

class Location
{
public:
	Location(Ports* ports, Ships* ships, char* location);
	~Location();

	void Arrive(Ships* ships, char* location);
	int BuyGoods(char* name, int amount, int money) const;
	int SellGoods(char* name, int amount, int money) const;
	int BuyCannons(int type, int amount, int money) const;
	int SellCannons(int type, int amount, int money) const;
	Ship* PreviewShip(int choice) const;
	static int BuyShip(Ship* oldShip, Ship* newShip, int money);
	int Depart(char* name) const;
	static int Repair(Ship* ship, int money);
	char* GetGoodsName(int number) const;
	int GetDistance(char* destination) const;
	char* GetName() const;
	void ShowAvailableGoods() const;
	void ShowAvailableShips() const;
	void ShowAvailableCannons() const;
	void ShowLocations() const;

private:
	char* name_;
	Ports* ports_;
	Port* port_;
	int shipAmount_;
	Ship** ships_;
	int* cannons_;
	int* cannonCost_;
};
