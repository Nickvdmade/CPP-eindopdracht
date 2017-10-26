#pragma once
#include "Ship.h"
#include "Inventory.h"
#include "PirateShip.h"

class Player
{
public:
	explicit Player(Ship* ship, Location* location);
	~Player();

	// Startup
	void ShowStartInfo() const;

	// in Port
	void Arrive(Ships* ships) const;
	char* BuyGoods() const;
	char* BuyGoods(char* name, int amount) const;
	char* SellGoods(char* name, int amount) const;
	char* BuyCannons(int type, int amount) const;
	char* SellCannons(int type, int amount) const;
	char* BuyShip(int choice) const;
	void ShowAvailableShips() const;
	void ShowAvailableCannons() const;
	void ShowLocations() const;
	char* Depart(char* destination);
	int Repair() const;
	int GetPiratesDefeated(); 
	int GetMoney() const;
	void SetMoney(int money) const;

	// in Battle
	bool Hit(int damage) const;
	int Shoot() const;
	void Surrender() const;
	bool Flee(PirateShip* pirateShip) const;
	int GetHitPoints() const;
	void PirateDefeated();

	//on Sea
	char* Sail();

private:
	char* destination_;
	int distance_;
	int piratesDefeated_;
	Location* location_;
	Ship* ship_;
	Inventory* inventory_;
};
