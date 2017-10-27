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

void Location::Arrive(Ships* ships, char* location)
{
	name_ = location;
	delete port_;
	port_ = new Port(ports_->GetPort(name_));
	RandomGenerator random;
	shipAmount_ = random.GetRandomNumber(1, 13);
	delete ships_;
	ships_ = new Ship*[shipAmount_];
	for (int i = 0; i < shipAmount_; i++)
	{
		ships_[i] = ships->GetShip(random.GetRandomNumber(0, 12));
	}
	cannons_[0] = random.GetRandomNumber(0, 5);
	cannons_[1] = random.GetRandomNumber(0, 3);
	cannons_[2] = random.GetRandomNumber(0, 2);
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

Ship* Location::PreviewShip(int choice) const
{
	if (choice < shipAmount_)
		return ships_[choice];
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

char* Location::GetName() const
{
	return name_;
}

int* Location::GetPrices() const
{
	return port_->GetPrices();
}

int Location::GetLocation(char* name) const
{
	return ports_->GetPosition(name);
}

void Location::ShowAvailableGoods() const
{
	std::cout << "NUMBER\tGOODS\t\tPRICE\tAMOUNT" << std::endl;
	port_->Print();
}

void Location::ShowAvailableShips() const
{
	std::cout << "NUMBER\tSHIP NAME\t\tPRICE\tLOADSPACE\tMAXCANNONS\tHITPOINTS\tWEIGHT\tSPECIALS" << std::endl;
	for (int i = 0; i < shipAmount_; i++)
	{
		std::cout << i + 1 << "\t";
		char* name = ships_[i]->GetName();
		std::cout << name << ":\t";
		if (strlen(name) < 15)
			std::cout << "\t";
		if (strlen(name) < 7)
			std::cout << "\t";
		std::cout << ships_[i]->GetPrice() << "\t";
		std::cout << ships_[i]->GetLoadSpace() << "\t\t";
		std::cout << ships_[i]->GetCannonAmount() << "\t\t";
		std::cout << ships_[i]->GetMaxHitPoints() << "\t\t";
		std::cout << ships_[i]->ShowWeight() << "\t";
		std::cout << ships_[i]->ShowSpecial() << std::endl;
	}
}

void Location::ShowAvailableCannons() const
{
	std::cout << "NUMBER\tCANNON TYPE\tPRICE\tAMOUNT" << std::endl;
	std::cout << "1\tlight:\t\t" << cannonCost_[0] << "\t" << cannons_[0] << std::endl;
	std::cout << "2\tmedium:\t\t" << cannonCost_[1] << "\t" << cannons_[1] << std::endl;
	std::cout << "3\theavy:\t\t" << cannonCost_[2] << "\t" << cannons_[2] << std::endl;
}

void Location::ShowLocations() const
{
	std::cout << "NUMBER\tPORT\t\t\tDISTANCE" << std::endl;
	int * distance = port_->GetDistances();
	char** portNames = ports_->GetNames();
	for (int i = 0; i < 24; i++)
	{
		if (distance[i] != 0)
		{
			std::cout << i + 1 << "\t";
			std::cout << portNames[i] << ":\t\t";
			if (strlen(portNames[i]) < 7)
				std::cout << "\t";
			std::cout << distance[i] << std::endl;
		}
	}
	delete portNames;
}
