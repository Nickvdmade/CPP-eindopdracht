#include "Port.h"
#include <iostream>

Port::Port(char* name, Goods** goods, int* distance)
{
	name_ = name;
	goods_ = goods;
	distance_ = distance;
}

Port::Port(Port& other)
{
	name_ = other.name_;
	distance_ = other.distance_;
	goods_ = new Goods*[15];
	for (int i = 0; i < 15; i++)
	{
		goods_[i] = new Goods(*other.goods_[i]);
	}
}

Port::~Port()
{
	for (int i = 0; i < 15; i++)
		delete goods_[i];
	delete goods_;
	delete distance_;
}

int* Port::GetDistances() const
{
	return distance_;
}

char* Port::GetName() const
{
	return name_;
}

Goods* Port::GetGoods(int number) const
{
	return goods_[number];
}

Port& Port::operator=(const Port& other)
{
	if (this != &other)
	{
		name_ = other.name_;
		distance_ = other.distance_;
		goods_ = new Goods*[15];
		for (int i = 0; i < 15; i++)
		{
			goods_[i] = new Goods(*other.goods_[i]);
		}
	}
	return *this;
}

void Port::Print()
{
	for (int i = 0; i < 15; i++)
	{
		goods_[i]->Print();
	}
}
