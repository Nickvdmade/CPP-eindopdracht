#pragma once

class Goods
{
public:
	Goods(char* name, int minPrice, int maxPrice, int minAmount, int maxAmount);
	~Goods();
	void Print();

private:
	char* name_;
	int minPrice_;
	int maxPrice_;
	int minAmount_;
	int maxAmount_;
};

