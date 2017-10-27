#pragma once

class Ship
{
public:
	Ship(Ship& other);
	Ship(char* type, int price, int loadSpace, int cannons, int hitPoints, bool small, int weight);
	~Ship();
	Ship& operator=(const Ship& other);

	bool Hit(int damage);
	bool HitPercentage(int percentage);
	int Repair(int money);

	char* GetName() const;
	int GetPrice() const;
	int GetLoadSpace() const;
	int GetCannonAmount() const;
	int GetMaxHitPoints() const;
	int GetHitPoints() const;
	int GetWeight() const;
	char* ShowWeight() const;
	char* ShowSpecial() const;
	bool isSmall() const;

	void ShowInfo() const;
	void ShowHitPoints() const;

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
