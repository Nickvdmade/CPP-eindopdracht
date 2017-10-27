#include "PirateShip.h"
#include "RandomGenerator.h"

PirateShip::PirateShip()
{
	RandomGenerator random;
	weight_ = random.GetRandomNumber(0, 2);
	if (weight_ == 0)
	{
		hitPoints_ = random.GetRandomNumber(50, 150);
		cannonAmount_ = random.GetRandomNumber(4, 12);
		cannons_ = new int[cannonAmount_];
		for (int i = 0; i < cannonAmount_; i++)
		{
			cannons_[i] = random.GetRandomNumber(0, 2);
		}
	}
	if (weight_ == 1)
	{
		hitPoints_ = random.GetRandomNumber(150, 250);
		cannonAmount_ = random.GetRandomNumber(10, 30);
		cannons_ = new int[cannonAmount_];
		for (int i = 0; i < cannonAmount_; i++)
		{
			cannons_[i] = random.GetRandomNumber(0, 2);
		}
	}
	if (weight_ == 2)
	{
		hitPoints_ = random.GetRandomNumber(250, 350);
		cannonAmount_ = random.GetRandomNumber(30, 50);
		cannons_ = new int[cannonAmount_];
		for (int i = 0; i < cannonAmount_; i++)
		{
			cannons_[i] = random.GetRandomNumber(0, 2);
		}
	}
}

PirateShip::~PirateShip()
{
	delete cannons_;
}

bool PirateShip::Hit(int damage)
{
	hitPoints_ -= damage;
	if (hitPoints_ <= 0)
		return true;
	return false;
}

int PirateShip::Shoot() const
{
	int damage = 0;
	RandomGenerator random;
	for (int i = 0; i < cannonAmount_; i++)
		damage += random.GetRandomNumber(0, (cannons_[i] + 1) * 2);
	return damage;
}

int PirateShip::GetHitPoints() const
{
	return hitPoints_;
}

int PirateShip::GetWeight() const
{
	return weight_;
}

void PirateShip::ShowCannons() const
{
	std::cout << "Installed cannons:\n";
	int light = 0;
	int medium = 0;
	int heavy = 0;
	for (int i = 0; i < cannonAmount_; i++)
	{
		if (cannons_[i] == 0)
			light++;
		if (cannons_[i] == 1)
			medium++;
		if (cannons_[i] == 2)
			heavy++;
	}
	std::cout << "\tLight cannons:\t" << light << std::endl;
	std::cout << "\tMedium cannons:\t" << medium << std::endl;
	std::cout << "\tHeavy cannons:\t" << heavy << std::endl;
}

void PirateShip::ShowHitPoints() const
{
	std::cout << "Pirate ship hitpoints: " << hitPoints_ << std::endl;
}
