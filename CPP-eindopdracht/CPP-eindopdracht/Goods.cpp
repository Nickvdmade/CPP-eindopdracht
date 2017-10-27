#include "Goods.h"
#include "RandomGenerator.h"
#include <iostream>

Goods::Goods(char* name, int minPrice, int maxPrice, int minAmount, int maxAmount)
{
	name_ = name;
	minPrice_ = minPrice;
	maxPrice_ = maxPrice;
	minAmount_ = minAmount;
	maxAmount_ = maxAmount;
	price_ = 0;
	amount_ = 0;
}

Goods::Goods(Goods& other)
{
	name_ = other.name_;
	minPrice_ = other.minPrice_;
	maxPrice_ = other.maxPrice_;
	RandomGenerator random;
	price_ = random.GetRandomNumber(minPrice_, maxPrice_);
	minAmount_ = other.minAmount_;
	maxAmount_ = other.maxAmount_;
	amount_ = random.GetRandomNumber(minAmount_, maxAmount_);
}

Goods::~Goods()
{

}

Goods& Goods::operator=(const Goods& other)
{
	if (this != &other)
	{
		name_ = other.name_;
		minPrice_ = other.minPrice_;
		maxPrice_ = other.maxPrice_;
		RandomGenerator random;
		price_ = random.GetRandomNumber(minPrice_, maxPrice_);
		minAmount_ = other.minAmount_;
		maxAmount_ = other.maxAmount_;
		amount_ = random.GetRandomNumber(minAmount_, maxAmount_);
	}
	return *this;
}

char* Goods::GetName() const
{
	return name_;
}

int Goods::GetPrice() const
{
	return price_;
}

int Goods::Buy(int amount, int money)
{
	if (amount_ >= amount && money >= (price_ * amount))
	{
		amount_ -= amount;
		return money - price_ * amount;
	}
	return -1;
}

int Goods::Sell(int amount, int money)
{
	amount_ += amount;
	return money + price_ * amount;
}

void Goods::Print() const
{
	std::cout << name_ << ":\t";
	if (strlen(name_) < 7)
		std::cout << "\t";
	std::cout << price_ << "\t" << amount_ << std::endl;
}
