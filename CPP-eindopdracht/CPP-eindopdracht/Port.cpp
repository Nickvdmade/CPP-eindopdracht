#include "Port.h"
#include <iostream>

Port::Port(char* name, Goods** goods, int* distance)
{
	name_ = name;
	goods_ = goods;
	distance_ = distance;
}

Port::~Port()
{
	delete goods_;
	delete distance_;
}

void Port::Print()
{
	std::cout << name_ << ":" << std::endl;
	for (int i = 0; i < 15; i++)
		goods_[i]->Print();
	for (int i = 0; i < 24; i++)
		std::cout << distance_[i] << " ";
	std::cout << std::endl << std::endl;
}
