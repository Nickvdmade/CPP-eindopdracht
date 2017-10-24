#pragma once
#include "Ports.h"

class Location
{
public:
	Location(Ports* ports, char* location);
	~Location();
	void Print();

private:
	char* name_;
	Ports* ports_;
	Port* port_;
};
