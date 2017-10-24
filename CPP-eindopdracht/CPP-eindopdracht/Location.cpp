#include "Location.h"
#include <iostream>

Location::Location(Ports* ports, char* location)
{
	ports_ = ports;
	name_ = location;
	port_ = new Port(ports_->GetPort(name_));
}

Location::~Location()
{
	
}

void Location::Print()
{
	std::cout << name_ << std::endl << std::endl;
	port_->Print();
}
