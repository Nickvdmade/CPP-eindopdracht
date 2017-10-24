#pragma once
#include "Goods.h"

class Port
{
public:
	Port(char* name, Goods** goods, int* distance);
	Port(Port& other);
	~Port();
	int* GetDistances() const;
	char* GetName() const;
	Goods* GetGoods(int number) const;
	Port& operator=(const Port& other);
	void Print();

private:
	char* name_;
	Goods** goods_;
	int* distance_;
};
