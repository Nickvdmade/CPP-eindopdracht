#include "Player.h"
#include <cstring>
#include <iostream>

Player::Player(Ship* ship, Location* location)
{
	destination_ = "Roatan";
	distance_ = 0;
	location_ = location;
	ship_ = new Ship(*ship);
	inventory_  = new Inventory(ship_, location_);
}

Player::~Player()
{
	delete ship_;
	delete inventory_;
}

char* Player::BuyGoods(char* name, int amount) const
{
	if (inventory_->IsLoadSpaceAvailable(amount))
	{
		int newMoney = location_->BuyGoods(name, amount, inventory_->GetMoney());
		if (newMoney != -1)
		{
			inventory_->SetMoney(newMoney);
			inventory_->AddGoods(name, amount);
			return "succes";
		}
		return "Not enough money or buying too many goods";
	}
	return "Not enough load space on ship";
}

char* Player::SellGoods(char* name, int amount) const
{
	if (inventory_->CanSellGoods(name, amount))
	{
		inventory_->SetMoney(location_->SellGoods(name, amount, inventory_->GetMoney()));
		inventory_->RemoveGoods(name, amount);
		return "succes";
	}
	return "Not enough goods to sell";
}

char* Player::BuyCannons(int type, int amount) const
{
	if (inventory_->IsCannonSpaceAvailable(amount))
	{
		int newMoney = location_->BuyCannons(type, amount, inventory_->GetMoney());
		if (newMoney != -1)
		{
			inventory_->SetMoney(newMoney);
			inventory_->AddCannons(type, amount);
			return "succes";
		}
		return "Not enough money or buying too many cannons";
	}
	return "Not enough cannon space on ship";
}

char* Player::SellCannons(int type, int amount) const
{
	if (inventory_->CanSellCannons(type, amount))
	{
		inventory_->SetMoney(location_->SellCannons(type, amount, inventory_->GetMoney()));
		inventory_->RemoveCannons(type, amount);
		return "succes";
	}
	return "Not enough cannons to sell";
}

char* Player::BuyShip(char* name) const
{
	Ship* newShip = location_->PreviewShip(name);
	if (newShip != nullptr)
	{
		if (inventory_->SufficientLoadSpace(newShip->GetLoadSpace()))
		{
			if (inventory_->SufficientCannonSpace(newShip->GetCannonAmount()))
			{
				inventory_->SetMoney(location_->BuyShip(ship_, newShip, inventory_->GetMoney()));
				return "succes";
			}
			return "Not enough cannon space on new ship";
		}
		return "Not enough load space on new ship";
	}
	return "Unknown ship name";
}

void Player::ShowAvailableGoods() const
{
	location_->ShowAvailableGoods();
}

void Player::ShowAvailableShips() const
{
	location_->ShowAvailableShips();
}

void Player::ShowAvailableCannons() const
{
	location_->ShowAvailableCannons();
}

void Player::ShowLocations() const
{
	location_->ShowLocations();
}

char* Player::Depart(char* destination)
{
	int distance = location_->GetDistance(destination);
	if (distance != -1)
	{
		destination_ = destination;
		distance_ = distance;
		return "succes";
	}
	return "Unknown destination";
}

int Player::Repair() const
{
	inventory_->SetMoney(ship_->Repair(inventory_->GetMoney()));
	return ship_->GetHitPoints();
}

void Player::ShowInfo() const
{
	ShowAvailableGoods();
	std::cout << std::endl;
	ShowAvailableShips();
	std::cout << std::endl;
	ShowAvailableCannons();
	std::cout << std::endl;
	ShowLocations();
}
