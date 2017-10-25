#pragma once

class Ship
{
public:
	Ship(Ship& other);
	Ship(char* type, int price, int loadSpace, int cannons, int hitPoints, bool small, int weight);
	~Ship();
	Ship& operator=(const Ship& other);

	char* GetName() const;
	int GetPrice() const;
	int Repair(int money);
	int GetLoadSpace() const;
	int GetCannonAmount() const;
	int GetHitPoints() const;

private:
	char* type_;
	int price_;
	int loadSpace_;
	int cannons_;
	int maxHitPoints_;
	int hitPoints_;
	bool small_; 
	int weight_;
};
