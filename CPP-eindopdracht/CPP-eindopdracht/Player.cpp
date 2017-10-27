#include "Player.h"
#include <iostream>
#include "RandomGenerator.h"
#include <string>

Player::Player(Ship* ship, Location* location)
{
	destination_ = location->GetName();
	distance_ = 0;
	location_ = location;
	currentLocation_ = 0;
	ship_ = new Ship(*ship);
	inventory_ = new Inventory(ship_, location_);
	piratesDefeated_ = 0;
}

Player::~Player()
{
	delete ship_;
	delete inventory_;
	delete location_;
}

void Player::ShowStartInfo() const
{
	std::cout << "You are in port " << destination_ << ".\n";
	std::cout << "This is your first ship:\n";
	ship_->ShowInfo();
	inventory_->ShowCannons();
	std::cout << std::endl;
	inventory_->ShowInfo();
}

void Player::Arrive(Ships* ships) const
{
	std::cout << "You have arrived at " << destination_ << ".\n\n";
	if (piratesDefeated_ > 0)
	{
		std::cout << "You defeated " << piratesDefeated_ << " pirates, well done.\n";
		inventory_->SetMoney(inventory_->GetMoney() + piratesDefeated_ * 10000);
		std::cout << "You received a bounty of " << piratesDefeated_ * 10000 << " gold pieces.\n\n";
	}
	ship_->ShowHitPoints();
	inventory_->ShowInfo();
	location_->Arrive(ships, destination_);
}

char* Player::BuyGoods() const
{
	location_->ShowAvailableGoods();
	int choice = 0;
	while (choice < 1 || choice > 15)
	{
		std::cout << "\nInput a valid number: ";
		std::cin.clear();
		std::cin >> choice;
		getchar();
		if (choice == 99)
			return "Action aborted.\n";
	}
	int amount = 0;
	while (amount < 1 || amount > 1200)
	{
		std::cout << "\nInput amount to buy: ";
		std::cin.clear();
		std::cin >> amount;
		getchar();		
	}
	switch(choice)
	{
	case bakstenen:
		return BuyGoods("bakstenen", amount);
	case laken:
		return BuyGoods("laken", amount);
	case katoen:
		return BuyGoods("katoen", amount);
	case verfstof:
		return BuyGoods("verfstof", amount);
	case vis:
		return BuyGoods("vis", amount);
	case hennep:
		return BuyGoods("hennep", amount);
	case aardappels:
		return BuyGoods("aardappels", amount);
	case rum:
		return BuyGoods("rum", amount);
	case zout:
		return BuyGoods("zout", amount);
	case suiker:
		return BuyGoods("suiker", amount);
	case tabak:
		return BuyGoods("tabak", amount);
	case graan:
		return BuyGoods("graan", amount);
	case vlees:
		return BuyGoods("vlees", amount);
	case hout:
		return BuyGoods("hout", amount);
	default:
		return "Something went wrong";
	}
}

char* Player::SellGoods() const
{
	inventory_->ShowGoods(location_);
	int choice = 0;
	while (choice < 1 || choice > 15)
	{
		std::cout << "\nInput a valid number: ";
		std::cin.clear();
		std::cin >> choice;
		getchar();
		if (choice == 99)
			return "Action aborted.\n";
	}
	int amount = 0;
	while (amount < 1 || amount > 1200)
	{
		std::cout << "\nInput amount to sell: ";
		std::cin.clear();
		std::cin >> amount;
		getchar();
	}
	switch (choice)
	{
	case bakstenen:
		return SellGoods("bakstenen", amount);
	case laken:
		return SellGoods("laken", amount);
	case katoen:
		return SellGoods("katoen", amount);
	case verfstof:
		return SellGoods("verfstof", amount);
	case vis:
		return SellGoods("vis", amount);
	case hennep:
		return SellGoods("hennep", amount);
	case aardappels:
		return SellGoods("aardappels", amount);
	case rum:
		return SellGoods("rum", amount);
	case zout:
		return SellGoods("zout", amount);
	case suiker:
		return SellGoods("suiker", amount);
	case tabak:
		return SellGoods("tabak", amount);
	case graan:
		return SellGoods("graan", amount);
	case vlees:
		return SellGoods("vlees", amount);
	case hout:
		return SellGoods("hout", amount);
	default:
		return "Something went wrong";
	}
}

char* Player::BuyCannons() const
{
	location_->ShowAvailableCannons();
	int choice = 0;
	while (choice < 1 || choice > 3)
	{
		std::cout << "\nInput a valid number: ";
		std::cin.clear();
		std::cin >> choice;
		getchar();
		if (choice == 99)
			return "Action aborted.\n";
	}
	int amount = 0;
	while (amount < 1 || amount > 5)
	{
		std::cout << "\nInput amount to buy: ";
		std::cin.clear();
		std::cin >> amount;
		getchar();
	}
	return BuyCannons(choice - 1, amount);
}

char* Player::SellCannons() const
{
	inventory_->ShowCannons();
	std::cout << "\nlight = 50 gold pieces\n";
	std::cout << "medium = 200 gold pieces\n";
	std::cout << "heavy = 1000 gold pieces\n";
	int choice = 0;
	while (choice < 1 || choice > 3)
	{
		std::cout << "\nInput a valid number: ";
		std::cin.clear();
		std::cin >> choice;
		getchar();
		if (choice == 99)
			return "Action aborted.\n";
	}
	int amount = 0;
	while (amount < 1 || amount > 5)
	{
		std::cout << "\nInput amount to sell: ";
		std::cin.clear();
		std::cin >> amount;
		getchar();
	}
	return SellCannons(choice - 1, amount);
}

char* Player::BuyShip() const
{
	location_->ShowAvailableShips();
	int choice = 0;
	while (choice < 1 || choice > 13)
	{
		std::cout << "\nInput a valid number: ";
		std::cin.clear();
		std::cin >> choice;
		getchar();
		if (choice == 99)
			return "Action aborted.\n";
	}
	return BuyShip(choice);
}

void Player::ShowAvailableShips() const
{
	location_->ShowAvailableShips();
}

void Player::ShowAvailableCannons() const
{
	location_->ShowAvailableCannons();
}

void Player::ShowLocations() const
{
	location_->ShowLocations();
}

void Player::ShowShipInfo() const
{
	ship_->ShowInfo();
	inventory_->ShowInventory();
	inventory_->ShowCannons();
}

char* Player::Depart()
{
	location_->ShowLocations();
	int choice = 0;
	while (choice < 1 || choice > 24 || choice == location_->GetLocation(destination_) + 1)
	{
		std::cout << "\nInput a valid number: ";
		std::cin.clear();
		std::cin >> choice;
		getchar();
		if (choice == 99)
			return "Action aborted.\n";
	}
	switch (choice)
	{
	case roatan:
		return Depart("Roatan");
	case belize:
		return Depart("Belize");
	case cayman:
		return Depart("Cayman");
	case evangelista:
		return Depart("Evangelista");
	case trinidad:
		return Depart("Trinidad");
	case portRoyale:
		return Depart("Port Royale");
	case santiago:
		return Depart("Santiago");
	case portAuPrince:
		return Depart("Port-au-prince");
	case santoDomingo:
		return Depart("Santo Domingo");
	case saintKitts:
		return Depart("Saint Kitts");
	case santaLucia:
		return Depart("Santa Lucia");
	case grenada:
		return Depart("Grenada");
	case portOfSpain:
		return Depart("Port of Spain");
	case puertoSanto:
		return Depart("Puerto Santo");
	case margarita:
		return Depart("Margarita");
	case caracas:
		return Depart("Caracas");
	case puertoCabello:
		return Depart("Puerto Cabello");
	case curacao:
		return Depart("Curacao");
	case coro:
		return Depart("Coro");
	case gibraltar:
		return Depart("Gibraltar");
	case maracaibo:
		return Depart("Maracaibo");
	case santaMarta:
		return Depart("Santa Marta");
	case cartagena:
		return Depart("Cartagena");
	case providence:
		return Depart("Providence");
	default:
		return "Something went wrong.";
	}
}

int Player::Repair() const
{
	inventory_->SetMoney(ship_->Repair(inventory_->GetMoney()));
	return ship_->GetHitPoints();
}

int Player::GetPiratesDefeated() 
{
	int pirates = piratesDefeated_;
	piratesDefeated_ = 0;
	return pirates;
}

int Player::GetMoney() const
{
	return inventory_->GetMoney();
}

void Player::SetMoney(int money) const
{
	inventory_->SetMoney(money);
}

bool Player::Hit(int damage) const
{
	return ship_->Hit(damage);
}

int Player::Shoot() const
{
	return inventory_->Shoot();
}

void Player::Surrender() const
{
	inventory_->ClearInventory();
}

bool Player::Flee(PirateShip* pirateShip) const
{
	int pirateWeight = pirateShip->GetWeight();
	int shipWeight = ship_->GetWeight();
	RandomGenerator random;
	int chance = random.GetRandomNumber(0, 100);
	if (shipWeight == 0)
	{
		if (pirateWeight == 0)
			if (chance <= 50)
				return true;
		if (pirateWeight == 1)
			if (chance <= 60)
				return true;
		if (pirateWeight == 2)
			if (chance <= 75)
				return true;
		return false;
	}
	if (shipWeight == 1)
	{
		if (pirateWeight == 0)
			if (chance <= 30)
				return true;
		if (pirateWeight == 1)
			if (chance <= 40)
				return true;
		if (pirateWeight == 2)
			if (chance <= 55)
				return true;
		return false;
	}
	if (shipWeight == 2)
	{
		if (pirateWeight == 0)
			if (chance <= 5)
				return true;
		if (pirateWeight == 1)
			if (chance <= 15)
				return true;
		if (pirateWeight == 2)
			if (chance <= 30)
				return true;
		return false;
	}
	return false;
}

int Player::GetHitPoints() const
{
	return ship_->GetHitPoints();
}

void Player::ShowHitPoints() const
{
	ship_->ShowHitPoints();
}

void Player::ShowCannons() const
{
	inventory_->ShowCannons();
}

void Player::PirateDefeated()
{
	piratesDefeated_++;
}

int Player::GetWeight() const
{
	return ship_->GetWeight();
}

char* Player::Sail()
{
	char* message;
	RandomGenerator random;
	int ambush = random.GetRandomNumber(1, 5);
	if (ambush == 3)
		return "Pirates";
	int wind = random.GetRandomNumber(1, 20);
	if (wind <= 2)
		message = "No wind, no movement\t\t\t";
	else if (wind <= 4)
	{
		if (ship_->GetWeight() != 0)
			message = "Slight breeze, no movement\t\t";
		else
		{
			distance_--;
			message = "Slight breeze, one mile closer to destination";
		}
	}
	else if (wind <= 7)
	{
		if (ship_->GetWeight() != 2)
		{
			distance_--;
			message = "Weak wind, one mile closer to destination";
		}
		else
			message = "Weak wind, no movement\t\t\t";
	}
	else if (wind <= 17)
	{
		distance_--;
		message = "Normal wind, one mile closer to destination";
	}
	else if (wind <= 19)
	{
		distance_ -= 2;
		message = "Heavy wind, two miles closer to destination";
	}
	else
	{
		int damage = random.GetRandomNumber(1, 100);
		if (ship_->HitPercentage(damage))
			return "Storm, ship sunk";
		int direction = random.GetRandomNumber(1, 5);
		if (direction <= 2)
		{
			distance_++;
			message = "Storm, one mile further from destination, damage taken";
		}
		else if (direction <= 4)
			message = "Storm, no movement, damage taken";
		else
		{
			distance_--;
			message = "Storm, one mile closer to destination, damage taken";
		}
	}
	return message;
}

bool Player::HasArrived() const
{
	if (distance_ <= 0)
		return true;
	return false;
}

int Player::GetDistance() const
{
	if (distance_ < 0)
		return 0;
	return distance_;
}

char* Player::BuyGoods(char* name, int amount) const
{
	if (inventory_->IsLoadSpaceAvailable(amount))
	{
		int newMoney = location_->BuyGoods(name, amount, inventory_->GetMoney());
		if (newMoney != -1)
		{
			inventory_->SetMoney(newMoney);
			inventory_->AddGoods(name, amount);
			return "succes";
		}
		return "Not enough money or buying too many goods";
	}
	return "Not enough load space on ship";
}

char* Player::SellGoods(char* name, int amount) const
{
	if (inventory_->CanSellGoods(name, amount))
	{
		inventory_->SetMoney(location_->SellGoods(name, amount, inventory_->GetMoney()));
		inventory_->RemoveGoods(name, amount);
		return "succes";
	}
	return "Not enough goods to sell";
}

char* Player::BuyCannons(int type, int amount) const
{
	if (inventory_->IsCannonSpaceAvailable(amount))
	{
		int newMoney = location_->BuyCannons(type, amount, inventory_->GetMoney());
		if (newMoney != -1)
		{
			inventory_->SetMoney(newMoney);
			inventory_->AddCannons(type, amount);
			return "succes";
		}
		return "Not enough money or buying too many cannons";
	}
	return "Not enough cannon space on ship";
}

char* Player::SellCannons(int type, int amount) const
{
	if (inventory_->CanSellCannons(type, amount))
	{
		inventory_->SetMoney(location_->SellCannons(type, amount, inventory_->GetMoney()));
		inventory_->RemoveCannons(type, amount);
		return "succes";
	}
	return "Not enough cannons to sell";
}

char* Player::BuyShip(int choice) const
{
	Ship* newShip = location_->PreviewShip(choice - 1);
	if (newShip != nullptr)
	{
		if (inventory_->SufficientLoadSpace(newShip->GetLoadSpace()))
		{
			if (inventory_->SufficientCannonSpace(newShip->GetCannonAmount()))
			{
				inventory_->SetMoney(location_->BuyShip(ship_, newShip, inventory_->GetMoney()));
				inventory_->NewShip(ship_);
				return "succes";
			}
			return "Not enough cannon space on new ship";
		}
		return "Not enough load space on new ship";
	}
	return "Unknown ship name";
}

char* Player::Depart(char* destination)
{
	int distance = location_->GetDistance(destination);
	if (distance != -1)
	{
		destination_ = destination;
		distance_ = distance;
		return "succes";
	}
	return "Unknown destination";
}
