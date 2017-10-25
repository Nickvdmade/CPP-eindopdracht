#include "Location.h"
#include <iostream>
#include "RandomGenerator.h"
#include "Ships.h"

Location::Location(Ports* ports, Ships* ships, char* location)
{
	name_ = location;
	ports_ = ports;
	port_ = new Port(ports_->GetPort(name_));
	RandomGenerator random;
	shipAmount_ = random.GetRandomNumber(1, 13);
	ships_ = new Ship*[shipAmount_];
	for (int i = 0; i < shipAmount_; i++)
	{
		ships_[i] = ships->GetShip(random.GetRandomNumber(0, 12));
	}
	cannons_ = new int[3];
	cannons_[0] = random.GetRandomNumber(0, 5);
	cannons_[1] = random.GetRandomNumber(0, 3);
	cannons_[2] = random.GetRandomNumber(0, 2);
	cannonCost_ = new int[3];
	cannonCost_[0] = 50;
	cannonCost_[1] = 200;
	cannonCost_[2] = 1000;
}

Location::~Location()
{
	delete port_;
	delete ships_;
	delete cannons_;
	delete cannonCost_;
}

int Location::BuyGoods(char* name, int amount, int money) const
{
	return port_->BuyGoods(name, amount, money);
}

int Location::SellGoods(char* name, int amount, int money) const
{
	return port_->SellGoods(name, amount, money);
}

int Location::BuyCannons(int type, int amount, int money) const
{
	if (cannons_[type] >= amount && money >= cannonCost_[type] * amount)
	{
		cannons_[type] -= amount;
		return money -= cannonCost_[type] * amount;
	}
	return -1;
}

int Location::SellCannons(int type, int amount, int money) const
{
	cannons_[type] += amount;
	return money += cannonCost_[type] * amount;
}

Ship* Location::PreviewShip(char* name) const
{
	for (int i = 0; i < shipAmount_; i++)
	{
		if (strcmp(ships_[i]->GetName(), name) == 0)
		{
			return ships_[i];
		}
	}
	return nullptr;
}

int Location::BuyShip(Ship* oldShip, Ship* newShip, int money)
{
	money += oldShip->GetPrice();
	*oldShip = *newShip;
	return money - newShip->GetPrice();
}

int Location::Depart(char* name) const
{
	int* distance = port_->GetDistances();
	int position = ports_->GetPosition(name);
	return distance[position];
}

int Location::Repair(Ship* ship, int money)
{
	return ship->Repair(money);
}

char* Location::GetGoodsName(int number) const
{
	return port_->GetGoods(number)->GetName();
}

int Location::GetDistance(char* destination) const
{
	int * distance = port_->GetDistances();
	char** portNames = ports_->GetNames();
	for (int i = 0; i < 24; i++)
	{
		if (strcmp(portNames[i], destination) == 0)
			return distance[i];
	}
	return -1;
}

void Location::ShowAvailableGoods() const
{
	std::cout << "GOODS\t\tPRICE\tAMOUNT" << std::endl;
	port_->Print();
}

void Location::ShowAvailableShips() const
{
	std::cout << "SHIP NAME\t\tPRICE" << std::endl;
	for (int i = 0; i < shipAmount_; i++)
	{
		char* name = ships_[i]->GetName();
		std::cout << name << ":\t";
		if (strlen(name) < 15)
			std::cout << "\t";
		if (strlen(name) < 7)
			std::cout << "\t";
		std::cout << ships_[i]->GetPrice() << std::endl;
	}
}

void Location::ShowAvailableCannons() const
{
	std::cout << "CANNON TYPE\tPRICE\tAMOUNT" << std::endl;
	std::cout << "light:\t\t" << cannonCost_[0] << "\t" << cannons_[0] << std::endl;
	std::cout << "medium:\t\t" << cannonCost_[1] << "\t" << cannons_[1] << std::endl;
	std::cout << "heavy:\t\t" << cannonCost_[2] << "\t" << cannons_[2] << std::endl;
}

void Location::ShowLocations() const
{
	std::cout << "PORT\t\t\tDISTANCE" << std::endl;
	int * distance = port_->GetDistances();
	char** portNames = ports_->GetNames();
	for (int i = 0; i < 24; i++)
	{
		if (distance[i] != 0)
		{
			std::cout << portNames[i] << ":\t\t";
			if (strlen(portNames[i]) < 7)
				std::cout << "\t";
			std::cout << distance[i] << std::endl;
		}
	}
	delete portNames;
}
