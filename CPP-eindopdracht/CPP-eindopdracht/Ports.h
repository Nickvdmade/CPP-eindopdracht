#pragma once
#include "Port.h"

class Ports
{
public:
	Ports();
	~Ports();
	char** GetNames() const;
	Port GetPort(char* name) const;
	int GetPosition(char* name) const;

private:
	Port** ports_;

	void AddPorts() const;
};
