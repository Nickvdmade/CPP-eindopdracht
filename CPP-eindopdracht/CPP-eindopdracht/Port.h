#pragma once
#include "Goods.h"

class Port
{
public:
	Port(char* name, Goods** goods, int* distance);
	~Port();
	void Print();

private:
	char* name_;
	Goods** goods_;
	int* distance_;
};
