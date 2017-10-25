#pragma once

#include "Ship.h"

class Ships
{
public:
	Ships();
	~Ships();
	Ship* GetShip(int number) const;

private:
	Ship** ships_;
};
