#pragma once
#include "Goods.h"

class Port
{
public:
	Port(char* name, Goods** goods, int* distance);
	Port(const Port& other);
	~Port();
	int* GetDistances() const;
	char* GetName() const;
	Goods* GetGoods(int number) const;
	int* GetPrices() const;
	Port& operator=(const Port& other);

	int BuyGoods(char* name, int amount, int money) const;
	int SellGoods(char* name, int amount, int money) const;

	void Print() const;

private:
	char* name_;
	Goods** goods_;
	int* distance_;
};
