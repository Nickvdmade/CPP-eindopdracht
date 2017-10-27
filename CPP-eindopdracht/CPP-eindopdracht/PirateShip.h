#pragma once
#include <iostream>

class PirateShip
{
public:
	PirateShip();
	~PirateShip();

	bool Hit(int damage);
	int Shoot() const;
	int GetHitPoints() const;
	int GetWeight() const;
	void ShowCannons() const;
	void ShowHitPoints() const;

private:
	int hitPoints_;
	int cannonAmount_;
	int* cannons_;
	int weight_;
};
