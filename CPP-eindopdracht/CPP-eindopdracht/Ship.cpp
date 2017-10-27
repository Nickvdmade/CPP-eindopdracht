#include "Ship.h"
#include <iostream>

Ship::Ship(Ship& other)
{
	type_ = other.type_;
	price_ = other.price_;
	loadSpace_ = other.loadSpace_;
	cannons_ = other.cannons_;
	maxHitPoints_ = other.maxHitPoints_;
	hitPoints_ = other.hitPoints_;
	small_ = other.small_;
	weight_ = other.weight_;
}

Ship::Ship(char* type, int price, int loadSpace, int cannons, int hitPoints, bool small, int weight)
{
	type_ = type;
	price_ = price;
	loadSpace_ = loadSpace;
	cannons_ = cannons;
	maxHitPoints_ = hitPoints;
	hitPoints_ = hitPoints;
	small_ = small;
	weight_ = weight;
}

Ship::~Ship()
{

}

Ship& Ship::operator=(const Ship& other)
{
	type_ = other.type_;
	price_ = other.price_;
	loadSpace_ = other.loadSpace_;
	cannons_ = other.cannons_;
	maxHitPoints_ = other.maxHitPoints_;
	hitPoints_ = other.hitPoints_;
	small_ = other.small_;
	weight_ = other.weight_;
	return *this;
}

bool Ship::Hit(int damage)
{
	hitPoints_ -= damage;
	if (hitPoints_ <= 0)
		return true;
	return false;
}

bool Ship::HitPercentage(int percentage)
{
	hitPoints_ -= (hitPoints_ * percentage) / 100;
	if (hitPoints_ <= 0)
		return true;
	return false;
}

char* Ship::GetName() const
{
	return type_;
}

int Ship::GetPrice() const
{
	return price_;
}

int Ship::Repair(int money)
{
	for (;hitPoints_ < maxHitPoints_ && money != 0; money --)
	{
		hitPoints_ += 10;
	}
	if (hitPoints_ > maxHitPoints_)
		hitPoints_ = maxHitPoints_;
	return money;
}

int Ship::GetLoadSpace() const
{
	return loadSpace_;
}

int Ship::GetCannonAmount() const
{
	return cannons_;
}

int Ship::GetMaxHitPoints() const
{
	return maxHitPoints_;
}

int Ship::GetHitPoints() const
{
	return hitPoints_;
}

int Ship::GetWeight() const
{
	return weight_;
}

char* Ship::ShowWeight() const
{
	if (weight_ == 0)
		return "light";
	if (weight_ == 1)
		return "medium";
	return "heavy";
}

char* Ship::ShowSpecial() const
{
	if (small_)
		return "small";
	return "";
}

bool Ship::isSmall() const
{
	return small_;
}

void Ship::ShowInfo() const
{
	std::cout << "\tName:\t\t" << type_ << std::endl;
	std::cout << "\tLoadspace:\t" << loadSpace_ << std::endl;
	std::cout << "\tMax hitpoints:\t" << maxHitPoints_ << std::endl;
	std::cout << "\tWeight:\t\t" << ShowWeight() << std::endl;
	std::cout << "\tSmall ship:\t";
	if (small_)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
}

void Ship::ShowHitPoints() const
{
	std::cout << "Player ship hitpoints: " << hitPoints_ << std::endl;
}
