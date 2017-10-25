#include "Ship.h"

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

int Ship::GetHitPoints() const
{
	return hitPoints_;
}
