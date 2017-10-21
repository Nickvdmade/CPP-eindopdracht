#pragma once

class Ship
{
public:
	Ship(char* type, int price, int loadSpace, int cannons, int hitPoints, bool small, int weight);
	~Ship();

private:
	char* type_;
	int price_;
	int loadSpace_;
	int cannons_;
	int hitPoints_;
	bool small_; 
	int weight_;
};
