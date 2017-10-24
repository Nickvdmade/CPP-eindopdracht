#pragma once

class Goods
{
public:
	Goods(char* name, int minPrice, int maxPrice, int minAmount, int maxAmount);
	Goods(Goods& other);
	~Goods();
	Goods& operator=(const Goods& other);
	void Print();

private:
	char* name_;
	int minPrice_;
	int maxPrice_;
	int price_;
	int minAmount_;
	int maxAmount_;
	int amount_;
};

