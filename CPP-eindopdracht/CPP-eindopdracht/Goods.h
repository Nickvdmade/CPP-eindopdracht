#pragma once

class Goods
{
public:
	Goods(char* name, int minPrice, int maxPrice, int minAmount, int maxAmount);
	Goods(Goods& other);
	~Goods();
	Goods& operator=(const Goods& other);

	char* GetName() const;
	int GetPrice() const;
	int Buy(int amount, int money);
	int Sell(int amount, int money);

	void Print() const;

private:
	char* name_;
	int minPrice_;
	int maxPrice_;
	int price_;
	int minAmount_;
	int maxAmount_;
	int amount_;
};

