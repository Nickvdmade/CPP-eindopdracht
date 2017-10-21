#include "Goods.h"
#include <iostream>

Goods::Goods(char* name, int minPrice, int maxPrice, int minAmount, int maxAmount)
{
	name_ = name;
	minPrice_ = minPrice;
	maxPrice_ = maxPrice;
	minAmount_ = minAmount;
	maxAmount_ = maxAmount;
}

Goods::~Goods()
{

}

void Goods::Print()
{
	std::cout << name_ << ": " << minPrice_ << "-" << maxPrice_ << "  " << minAmount_ << "-" << maxAmount_ << std::endl;
}
