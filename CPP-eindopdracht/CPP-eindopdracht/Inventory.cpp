#include "Inventory.h"
#include <cstring>
#include <iostream>

Inventory::Inventory(Ship* ship, Location* location)
{
	money_ = 1000;
	maxLoadSpace_ = ship->GetLoadSpace();
	usedLoadSpace_ = 0;
	maxCannons_ = ship->GetCannonAmount();
	cannons_ = new int[maxCannons_];
	for (int i = 0; i < 2; i++)
		cannons_[i] = 0;
	for (int i = 2; i < maxCannons_; i++)
		cannons_[i] = -1;
	goodsNames_ = new char*[15];
	goodsAmount_ = new int[15];
	for (int i = 0; i < 15; i++)
	{
		goodsNames_[i] = location->GetGoodsName(i);
		goodsAmount_[i] = 0;
	}
}

Inventory::~Inventory()
{
	delete cannons_;
	delete goodsNames_;
	delete goodsAmount_;
}

bool Inventory::SufficientLoadSpace(int space) const
{
	if (usedLoadSpace_ <= space)
		return true;
	return false;
}

bool Inventory::SufficientCannonSpace(int space) const
{
	int count = 0;
	for (int i = 0; i < maxCannons_; i++)
	{
		if (cannons_[i] != -1)
			count++;
	}
	if (count <= space)
		return true;
	return false;
}

bool Inventory::IsLoadSpaceAvailable(int space) const
{
	if (space <= maxLoadSpace_ - usedLoadSpace_)
		return true;
	return false;
}

bool Inventory::CanSellGoods(char* name, int amount) const
{
	for (int i = 0; i < 15; i++)
		if (strcmp(goodsNames_[i], name) == 0)
			if (goodsAmount_[i] >= amount)
				return true;
	return false;
}

bool Inventory::IsCannonSpaceAvailable(int space) const
{
	int count = 0;
	for (int i = 0; i < maxCannons_; i++)
	{
		if (cannons_[i] == -1)
			count++;
	}
	if (count >= space)
		return true;
	return false;
}

bool Inventory::CanSellCannons(int type, int amount) const
{
	int count = 0;
	for (int i = 0; i < maxCannons_; i++)
	{
		if (cannons_[i] == type)
			count++;
	}
	if (count >= amount)
		return true;
	return false;
}

int Inventory::GetMoney() const
{
	return money_;
}

void Inventory::SetMoney(int money)
{
	money_ = money;
}

void Inventory::AddGoods(char* name, int amount) const
{
	for(int i = 0; i < 15; i++)
	{
		if(strcmp(goodsNames_[i], name) == 0)
		{
			goodsAmount_[i] += amount;
			return;
		}
	}
}

void Inventory::RemoveGoods(char* name, int amount) const
{
	for (int i = 0; i < 15; i++)
	{
		if (strcmp(goodsNames_[i], name) == 0)
		{
			goodsAmount_[i] -= amount;
			return;
		}
	}
}

void Inventory::AddCannons(int type, int amount) const
{
	for (int i = 0; i < maxCannons_ && amount > 0; i++)
	{
		if (cannons_[i] == -1)
		{
			cannons_[i] = type;
			amount--;
		}
	}
}

void Inventory::RemoveCannons(int type, int amount) const
{
	for (int i = 0; i < maxCannons_ && amount > 0; i++)
	{
		if (cannons_[i] == type)
		{
			cannons_[i] = -1;
			amount--;
		}
	}
}

void Inventory::SetLoadSpace(int space)
{
	maxLoadSpace_ = space;
}

void Inventory::ShowInfo() const
{
	std::cout << "Current gold: " << money_ << " pieces" << std::endl;
	std::cout << "Current inventory:" << std::endl;
	for (int i = 0; i < 15; i++)
	{
		std::cout << "\t" << goodsNames_[i] << ":\t";
		if (strlen(goodsNames_[i]) < 7)
			std::cout << "\t";
		std::cout << goodsAmount_[i] << std::endl;
	}
}

void Inventory::ShowCannons() const
{
	std::cout << "\tMax cannons:\t" << maxCannons_ << std::endl;
	std::cout << "\tInstalled cannons:\n";
	for (int i = 0; i < maxCannons_; i++)
	{
		if (cannons_[i] == 0)
			std::cout << "\t\tLight cannon\n";
		if (cannons_[i] == 1)
			std::cout << "\t\tMedium cannon\n";
		if (cannons_[i] == 2)
			std::cout << "\t\tHeavy cannon\n";
	}
}

int Inventory::Shoot() const
{
	int damage = 0;
	for (int i = 0; i < maxCannons_; i++)
		damage += (cannons_[i] + 1) * 2;
	return damage;
}

void Inventory::ClearInventory() const
{
	for (int i = 0; i < 15; i++)
		goodsAmount_[i] = 0;
}
