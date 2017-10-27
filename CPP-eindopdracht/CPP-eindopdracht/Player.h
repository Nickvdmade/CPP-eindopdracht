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
	char* SellGoods() const;
	char* BuyCannons() const;
	char* SellCannons() const;
	char* BuyShip() const;
	void ShowAvailableShips() const;
	void ShowAvailableCannons() const;
	void ShowLocations() const;
	void ShowShipInfo() const;
	char* Depart();
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
	void ShowHitPoints() const;
	void ShowCannons() const;
	void PirateDefeated();
	int GetWeight() const;

	//on Sea
	char* Sail();
	bool HasArrived() const;
	int GetDistance() const;

private:
	char* BuyGoods(char* name, int amount) const;
	char* SellGoods(char* name, int amount) const;
	char* BuyCannons(int type, int amount) const;
	char* SellCannons(int type, int amount) const;
	char* BuyShip(int choice) const;
	char* Depart(char* destination);

	char* destination_;
	int distance_;
	int piratesDefeated_;
	Location* location_;
	int currentLocation_;
	Ship* ship_;
	Inventory* inventory_;

	enum goods
	{
		bakstenen = 1,
		laken,
		cacao,
		katoen,
		verfstof,
		vis,
		hennep,
		aardappels,
		rum,
		zout,
		suiker,
		tabak,
		graan,
		vlees,
		hout
	};

	enum ports
	{
		roatan = 1,
		belize,
		cayman,
		evangelista,
		trinidad,
		portRoyale,
		santiago,
		portAuPrince,
		santoDomingo,
		saintKitts,
		santaLucia,
		grenada,
		portOfSpain,
		puertoSanto,
		margarita,
		caracas,
		puertoCabello,
		curacao,
		coro,
		gibraltar,
		maracaibo,
		santaMarta,
		cartagena,
		providence
	};
};
