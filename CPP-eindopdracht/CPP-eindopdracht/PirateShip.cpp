#include "PirateShip.h"
#include "RandomGenerator.h"

PirateShip::PirateShip()
{
	RandomGenerator random;
	weight_ = random.GetRandomNumber(0, 2);
	if (weight_ == 0)
	{
		hitPoints_ = random.GetRandomNumber(100, 200);
		cannonAmount_ = random.GetRandomNumber(8, 24);
		cannons_ = new int[cannonAmount_];
		for (int i = 0; i < cannonAmount_; i++)
		{
			cannons_[i] = random.GetRandomNumber(0, 2);
		}
	}
	if (weight_ == 1)
	{
		hitPoints_ = random.GetRandomNumber(220, 280);
		cannonAmount_ = random.GetRandomNumber(16, 36);
		cannons_ = new int[cannonAmount_];
		for (int i = 0; i < cannonAmount_; i++)
		{
			cannons_[i] = random.GetRandomNumber(0, 2);
		}
	}
	if (weight_ == 2)
	{
		hitPoints_ = random.GetRandomNumber(300, 340);
		cannonAmount_ = random.GetRandomNumber(40, 50);
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
	for (int i = 0; i < cannonAmount_; i++)
		damage += (cannons_[i] + 1) * 2;
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