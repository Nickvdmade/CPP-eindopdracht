#pragma once

#include "Ship.h"
#include "Location.h"

class Inventory
{
public:
	explicit Inventory(Ship* ship, Location* location);
	~Inventory();

	//in Port
	bool SufficientLoadSpace(int space) const;
	bool SufficientCannonSpace(int space) const;
	bool IsLoadSpaceAvailable(int space) const;
	bool CanSellGoods(char* name, int amount) const;
	bool IsCannonSpaceAvailable(int space) const;
	bool CanSellCannons(int type, int amount) const;
	int GetMoney() const;
	void SetMoney(int money);
	void AddGoods(char* name, int amount);
	void RemoveGoods(char* name, int amount);
	void AddCannons(int type, int amount) const;
	void RemoveCannons(int type, int amount) const;
	void SetLoadSpace(int space);
	void ShowInfo() const;
	void ShowInventory() const;
	void ShowCannons() const;
	void ShowGoods(Location* location) const;
	void ShowLoadSpace() const;

	//in Battle
	int Shoot() const;
	void ClearInventory() const;
	void NewShip(Ship* ship);

private:
	void OrderCannons() const;

	int money_;
	int maxLoadSpace_;
	int usedLoadSpace_;
	int maxCannons_;
	int* cannons_;
	char** goodsNames_;
	int* goodsAmount_;
};
