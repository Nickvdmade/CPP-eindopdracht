#include "Ship.h"

Ship::Ship(char* type, int price, int loadSpace, int cannons, int hitPoints, bool small, int weight)
{
	type_ = type;
	price_ = price;
	loadSpace_ = loadSpace;
	cannons_ = cannons;
	hitPoints_ = hitPoints;
	small_ = small;
	weight_ = weight;
}

Ship::~Ship()
{

}
