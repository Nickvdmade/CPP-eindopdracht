#pragma once
#include "Port.h"

class Ports
{
public:
	Ports();
	~Ports();
	void Print();

private:
	Port** ports_;

	void AddPorts() const;
};
