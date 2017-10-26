#include "Player.h"
#include <cstring>
#include <iostream>
#include "RandomGenerator.h"
#include <string>

Player::Player(Ship* ship, Location* location)
{
	destination_ = location->GetName();
	distance_ = 0;
	location_ = location;
	ship_ = new Ship(*ship);
	inventory_  = new Inventory(ship_, location_);
	piratesDefeated_ = 0;
}

Player::~Player()
{
	delete ship_;
	delete inventory_;
	delete location_;
}

void Player::ShowStartInfo() const
{
	std::cout << "You are in port " << destination_ << ".\n";
	std::cout << "This is your first ship:\n";
	ship_->ShowInfo();
	inventory_->ShowCannons();
	std::cout << std::endl;
	inventory_->ShowInfo();
}

void Player::Arrive(Ships* ships) const
{
	std::cout << "You have arrived at " << destination_ << ".\n\n";
	if (piratesDefeated_ > 0)
	{
		std::cout << "You defeated " << piratesDefeated_ << " pirates, well done.\n";
		inventory_->SetMoney(inventory_->GetMoney() + piratesDefeated_ * 1000);
		std::cout << "You received a bounty of " << piratesDefeated_ * 1000 << ".\n\n";
	}
	ship_->ShowHitPoints();
	inventory_->ShowInfo();
}

char* Player::BuyGoods() const
{
	location_->ShowAvailableGoods();

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

char* Player::BuyShip(int choice) const
{
	Ship* newShip = location_->PreviewShip(choice - 1);
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

int Player::GetPiratesDefeated()
{
	int pirates = piratesDefeated_;
	piratesDefeated_ = 0;
	return pirates;
}

bool Player::Hit(int damage) const
{
	return ship_->Hit(damage);
}

int Player::Shoot() const
{
	return inventory_->Shoot();
}

void Player::Surrender() const
{
	inventory_->ClearInventory();
}

bool Player::Flee(PirateShip* pirateShip) const
{
	int pirateWeight = pirateShip->GetWeight();
	int shipWeight = ship_->GetWeight();
	RandomGenerator random;
	int chance = random.GetRandomNumber(0, 100);
	if (shipWeight == 0)
	{
		if (pirateWeight == 0)
			if (chance >= 50)
				return true;
		if (pirateWeight == 1)
			if (chance >= 60)
				return true;
		if (pirateWeight == 2)
			if (chance >= 75)
				return true;
		return false;
	}
	if (shipWeight == 1)
	{
		if (pirateWeight == 0)
			if (chance >= 30)
				return true;
		if (pirateWeight == 1)
			if (chance >= 40)
				return true;
		if (pirateWeight == 2)
			if (chance >= 55)
				return true;
		return false;
	}
	if (shipWeight == 2)
	{
		if (pirateWeight == 0)
			if (chance >= 5)
				return true;
		if (pirateWeight == 1)
			if (chance >= 15)
				return true;
		if (pirateWeight == 2)
			if (chance >= 30)
				return true;
		return false;
	}
	return false;
}

int Player::GetHitPoints() const
{
	return ship_->GetHitPoints();
}

void Player::PirateDefeated()
{
	piratesDefeated_++;
}

char* Player::Sail()
{
	char* message;
	RandomGenerator random;
	int ambush = random.GetRandomNumber(1, 5);
	if (ambush == 3)
		return "Pirates";
	int wind = random.GetRandomNumber(1, 20);
	if (wind <= 2)
		message = "No wind, no movement";
	else if (wind <= 4)
	{
		if (ship_->GetWeight() != 0)
			message = "Slight breeze, no movement";
		else
		{
			distance_--;
			message = "Slight breeze, one mile closer to destination";
		}
	}
	else if (wind <= 7)
	{
		if (ship_->GetWeight() != 2)
		{
			distance_--;
			message = "Weak wind, one mile closer to destination";
		}
		else
			message = "Weak wind, no movement";
	}
	else if (wind <= 17)
	{
		distance_--;
		message = "Normal wind, one mile closer to destination";
	}
	else if (wind <= 19)
	{
		distance_ -= 2;
		message = "Heavy wind, two miles closer to destination";
	}
	else
	{
		int damage = random.GetRandomNumber(1, 100);
		if (ship_->HitPercentage(damage))
			return "Storm, ship sunk";
		int hitPoints = ship_->GetHitPoints();
		int direction = random.GetRandomNumber(1, 5);
		if (direction <= 2)
		{
			distance_++;
			message = "Storm, one mile further from destination, damage taken";
		}
		else if (direction <= 4)
			message = "Storm, no movement, damage taken";
		else
		{
			distance_--;
			message = "Storm, one mile closer to destination, damage taken";
		}
	}
	if (distance_ <= 0)
		message = "Arrived";
	return message;
}
