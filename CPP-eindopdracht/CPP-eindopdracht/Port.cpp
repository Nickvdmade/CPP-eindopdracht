#include "Port.h"
#include <iostream>

Port::Port(char* name, Goods** goods, int* distance)
{
	name_ = name;
	goods_ = goods;
	distance_ = distance;
}

Port::Port(const Port& other)
{
	name_ = other.name_;
	distance_ = new int[24];
	for (int i = 0; i < 24; i++)
		distance_[i] = other.distance_[i];
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
		distance_ = new int[24];
		for (int i = 0; i < 24; i++)
			distance_[i] = other.distance_[i];
		goods_ = new Goods*[15];
		for (int i = 0; i < 15; i++)
		{
			goods_[i] = new Goods(*other.goods_[i]);
		}
	}
	return *this;
}

int Port::BuyGoods(char* name, int amount, int money) const
{
	for (int i = 0; i < 15; i++)
	{
		if (strcmp(goods_[i]->GetName(), name) == 0)
		{
			return goods_[i]->Buy(amount, money);
		}
	}
	return -1;
}

int Port::SellGoods(char* name, int amount, int money) const
{
	for (int i = 0; i < 15; i++)
	{
		if (strcmp(goods_[i]->GetName(), name) == 0)
		{
			return goods_[i]->Sell(amount, money);
		}
	}
	return money;
}

void Port::Print() const
{
	for (int i = 0; i < 15; i++)
	{
		goods_[i]->Print();
	}
}
