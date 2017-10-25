#pragma once

#include "Ship.h"
#include "Location.h"

class Inventory
{
public:
	explicit Inventory(Ship* ship, Location* location);
	~Inventory();
	bool SufficientLoadSpace(int space) const;
	bool SufficientCannonSpace(int space) const;
	bool IsLoadSpaceAvailable(int space) const;
	bool CanSellGoods(char* name, int amount) const;
	bool IsCannonSpaceAvailable(int space) const;
	bool CanSellCannons(int type, int amount) const;
	int GetMoney() const;
	void SetMoney(int money);
	void AddGoods(char* name, int amount) const;
	void RemoveGoods(char* name, int amount) const;
	void AddCannons(int type, int amount) const;
	void RemoveCannons(int type, int amount) const;
	void SetLoadSpace(int space);

private:
	int money_;
	int maxLoadSpace_;
	int usedLoadSpace_;
	int maxCannons_;
	int* cannons_;
	char** goodsNames_;
	int* goodsAmount_;
};
