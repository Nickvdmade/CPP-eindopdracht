#include "Inventory.h"
#include <cstring>
#include <iostream>
#include "RandomGenerator.h"

Inventory::Inventory(Ship* ship, Location* location)
{
	money_ = 10000;
	maxLoadSpace_ = ship->GetLoadSpace();
	usedLoadSpace_ = 0;
	maxCannons_ = ship->GetCannonAmount();
	cannons_ = new int[50];
	for (int i = 0; i < 50; i++)
		cannons_[i] = -1;
	for (int i = 0; i < 3; i++)
		cannons_[i] = 0;
	for (int i = 2; i < 6; i++)
		cannons_[i] = 1;
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

void Inventory::AddGoods(char* name, int amount)
{
	for(int i = 0; i < 15; i++)
	{
		if(strcmp(goodsNames_[i], name) == 0)
		{
			goodsAmount_[i] += amount;
			usedLoadSpace_ += amount;
			return;
		}
	}
}

void Inventory::RemoveGoods(char* name, int amount)
{
	for (int i = 0; i < 15; i++)
	{
		if (strcmp(goodsNames_[i], name) == 0)
		{
			goodsAmount_[i] -= amount;
			usedLoadSpace_ -= amount;
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
	OrderCannons();
}

void Inventory::SetLoadSpace(int space)
{
	maxLoadSpace_ = space;
}

void Inventory::ShowInfo() const
{
	std::cout << "Current gold: " << money_ << " pieces" << std::endl;
	ShowInventory();
}

void Inventory::ShowInventory() const
{
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
	std::cout << "Max cannons:\t" << maxCannons_ << std::endl;
	int light = 0;
	int medium = 0;
	int heavy = 0;
	for (int i = 0; i < maxCannons_; i++)
	{
		if (cannons_[i] == 0)
			light++;
		if (cannons_[i] == 1)
			medium++;
		if (cannons_[i] == 2)
			heavy++;
	}
	std::cout << "1\tLight cannons:\t" << light << std::endl;
	std::cout << "2\tMedium cannons:\t" << medium << std::endl;
	std::cout << "3\tHeavy cannons:\t" << heavy << std::endl;
}

void Inventory::ShowGoods(Location* location) const
{
	std::cout << "NUMBER\tGOODS\t\tPRICE\tAMOUNT" << std::endl;
	int* goodsPrice = location->GetPrices();
	for (int i = 0; i < 15; i++)
	{
		std::cout << i + 1 << "\t" << goodsNames_[i] << ":\t";
		if (strlen(goodsNames_[i]) < 7)
			std::cout << "\t";
		std::cout << goodsPrice[i] << "\t";
		std::cout << goodsAmount_[i] << std::endl;
	}
	delete goodsPrice;
}

void Inventory::ShowLoadSpace() const
{
	std::cout << "\nMax load space: " << maxLoadSpace_ << std::endl;
	std::cout << "Used load space: " << usedLoadSpace_ << std::endl;
}

int Inventory::Shoot() const
{
	int damage = 0;
	RandomGenerator random;
	for (int i = 0; i < maxCannons_; i++)
		damage += random.GetRandomNumber(0, (cannons_[i] + 1) * 2);
	return damage;
}

void Inventory::ClearInventory() const
{
	for (int i = 0; i < 15; i++)
		goodsAmount_[i] = 0;
}

void Inventory::NewShip(Ship* ship)
{
	maxLoadSpace_ = ship->GetLoadSpace();

	maxCannons_ = ship->GetCannonAmount();
}

void Inventory::OrderCannons() const
{
	int i = 0;
	int j = 49;
	while (i != j)
	{
		if (cannons_[i] == -1)
			if (cannons_[j] != -1)
			{
				int swap = cannons_[i];
				cannons_[i] = cannons_[j];
				cannons_[j] = swap;
				i++;
				j--;
			}
			else
				j--;
		else
			i++;
	}
}
