#pragma once

class Ship
{
private:
	char* type_;
	int price_;
	int loadSpace_;
	int cannons_;
	int hitPoints_;
	char* weight_;
	bool small_;

public:
	Ship(char* shipInfo);
	~Ship();
};
