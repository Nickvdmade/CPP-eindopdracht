#include "Game.h"
#include <iostream>

Game::Game()
{
	ships_ = new Ships();
	ports_ = new Ports();
	startLocation_ = new Location(ports_, ships_, "Roatan");
	player_ = new Player(ships_->GetShip(0), startLocation_);
	state_ = 0;
	goal_ = 1000000;
	inBattle_ = false;
	pirateShip_ = nullptr;
}

Game::~Game()
{
	delete ships_;
	delete ports_;
	delete player_;
}

void Game::StartGame()
{
	Startup();
	system("cls");
	StartInfo();
	system("cls");
	GameLoop();
}

void Game::Startup()
{
	std::cout << "Welcome to 'Trade your way up (or down)'\n\n";
	std::cout << "You are a trader. ";
	std::cout << "You have just spent your life savings to buy your first ship.\n";
	std::cout << "Your goal is to build a trade emperium worth 1,000,000 gold pieces.\n";
	std::cout << "To achieve this goal, you must buy and sell goods in different ports.\n";
	std::cout << "You can also buy new ships.\n";
	std::cout << "But beware, the open sea is full of danger, like STORMS and PIRATES!!!\n";
	std::cout << "Expand your arsenal of cannons to combat these pirates and earn their bounty.\n\n";
	std::cout << "Press enter to start your adventure to fame and fortune.\n";
	getchar();
}

void Game::StartInfo() const
{
	player_->ShowStartInfo();
	std::cout << "\nPress enter to continue.\n";
	getchar();
}

void Game::GameLoop()
{
	while (state_ != exit)
	{
		switch (state_)
		{
		case inPort:
			InPort();
			break;
		case onSea:
			OnSea();
			break;
		case inBattle:
			PrepareForBattle();
			InBattle();
			break;
		case gameOver:
			GameOver();
			break;
		case gameWon:
			GameWon();
			break;
		case theAnswer:
			Cheat();
			break;
		default:
			break;
		}
	}
}

void Game::InPort()
{
	system("cls");
	std::cout << "In port " << player_->GetLocation() << ", options:\n";
	std::cout << "\t1: Buy goods\n";
	std::cout << "\t2: Sell goods\n";
	std::cout << "\t3: Buy cannons\n";
	std::cout << "\t4: Sell cannons\n";
	std::cout << "\t5: Buy ship\n";
	std::cout << "\t6: Fix ship\n";
	std::cout << "\t7: Depart\n";
	std::cout << "\t8: Retire\n\n";
	std::cout << "Current gold: " << player_->GetMoney() << " pieces.\n";
	int choice = 0;
	while(choice < 1 || choice > 8)
	{
		std::cout << "\nInput a valid number: ";
		std::cin.clear();
		std::cin >> choice;
		getchar();
		if (choice == theAnswer)
		{
			state_ = theAnswer;
			return;
		}
	}
	char* result;
	switch(choice)
	{
	case buyGoods:
		result = player_->BuyGoods();
		if (strcmp(result, "succes") == 0)
			std::cout << "The goods were transfered to your ship.\n";
		else
			std::cout << result << std::endl;
		getchar();
		break;
	case sellGoods:
		result = player_->SellGoods();
		if (strcmp(result, "succes") == 0)
			std::cout << "The goods were removed from your ship.\n";
		else
			std::cout << result << std::endl;
		getchar();
		break;
	case buyCannons:
		result = player_->BuyCannons();
		if (strcmp(result, "succes") == 0)
			std::cout << "The cannons were added to your arsenal.\n";
		else
			std::cout << result << std::endl;
		getchar();
		break;
	case sellCannons:
		result = player_->SellCannons();
		if (strcmp(result, "succes") == 0)
			std::cout << "The cannons were removed from your arsenal.\n";
		else
			std::cout << result << std::endl;
		getchar();
		break;
	case buyShip:
		result = player_->BuyShip();
		if (strcmp(result, "succes") == 0)
		{
			std::cout << "You are now the proud owner of a new ship.\n";
			std::cout << "Your cannons and goods were transfered to your new ship.\n";
			player_->ShowShipInfo();
		}
		else
			std::cout << result << std::endl;
		getchar();
		break;
	case fixShip:
		std::cout << "The local shipyard has repaired your ship up to " << player_->Repair() << " hitpoints.\n";
		getchar();
		break;
	case depart:
		result = player_->Depart();
		if (strcmp(result, "succes") == 0)
		{
			std::cout << "Raise the anker and hoist the sail!!\n";
			state_ = onSea;
		}
		else
			std::cout << result << std::endl;
		getchar();
		break;
	case retire:
		std::cout << "Being a trader is hard work, you have chosen to take an early retirement.\n";
		std::cout << "\nPress enter to continue\n";
		getchar();
		state_ = gameOver;
		break;
	default:
		break;
	}
	if (player_->GetMoney() >= goal_)
		state_ = gameWon;
}

void Game::OnSea()
{
	system("cls");
	std::cout << "While traversing the open sea...\n\n";
	char* message = player_->Sail();
	while (!player_->HasArrived())
	{
		if (strcmp(message, "Pirates") == 0)
		{
			std::cout << "Ahoy captain, there be pirates!\nPrepare for battle...\n";
			getchar();
			state_ = inBattle;
			return;
		}
		if(strcmp(message, "Storm, ship sunk") == 0)
		{
			std::cout << "Alas, poor sailor, a terrible storm has sunk your ship.\n";
			getchar();
			state_ = gameOver;
			return;
		}
		std::cout << message << "\t\t" << player_->GetDistance() << " miles to go.";
		message = player_->Sail();
		getchar();
	}
	std::cout << message << "\t\t" << player_->GetDistance() << " miles to go.";
	getchar();
	std::cout << "\nLand ho!\n";
	player_->Arrive(ships_);
	if (player_->GetMoney() >= goal_)
	{
		std::cout << "\nPress enter to continue.\n";
		getchar();
		state_ = gameWon;
		return;
	}
	std::cout << "\nPress enter to visit the port.\n";
	getchar();
	state_ = inPort;
}

void Game::PrepareForBattle()
{
	if (pirateShip_ == nullptr)
	{	
		pirateShip_ = new PirateShip();
		int pirateWeight = pirateShip_->GetWeight();
		int playerWeight = player_->GetWeight();
		if (playerWeight < pirateWeight)
			std::cout << "Captain, the pirate ship is too big, we should surrender!\n\n";
		else if (playerWeight == pirateWeight)
			std::cout << "Captain, the pirate ship is equal to ours, we can fight or flee!\n\n";
		else
			std::cout << "Captain, it's just a small pirate ship, we should fight!\n\n";
		getchar();
	}
}

void Game::InBattle()
{
	system("cls");
	player_->ShowHitPoints();
	player_->ShowCannons();
	std::cout << std::endl;
	pirateShip_->ShowHitPoints();
	pirateShip_->ShowCannons();
	std::cout << "\nIn battle, options:\n";
	std::cout << "\t1: Fire!\n";
	std::cout << "\t2: Flee!\n";
	std::cout << "\t3: Surrender!\n";
	int choice = 0;
	while (choice < 1 || choice > 3)
	{
		std::cout << "\nInput a valid number: ";
		std::cin >> choice;
		getchar();
		if (choice == theAnswer)
		{
			state_ = theAnswer;
			return;
		}
	}
	switch (choice)
	{
	case 1:
		std::cout << "You hit the pirate ship with " << player_->Shoot() << " damage.\n";
		if (pirateShip_->Hit(player_->Shoot()))
		{
			std::cout << "You sunk the pirate ship!\n";
			std::cout << "\nPress enter to continue on your journey.\n";
			getchar();
			state_ = onSea;
			delete pirateShip_;
			pirateShip_ = nullptr;
			player_->PirateDefeated();
			return;
		}
		std::cout << "The pirate ship shoots back and hits you with " << pirateShip_->Shoot() << " damage.\n";
		if (player_->Hit(pirateShip_->Shoot()))
		{
			std::cout << "The pirates defeated you,\nthey laugh and sing while you and your crew sink to the bottom of the ocean!\n";
			std::cout << "\nPress enter to continue.\n";
			getchar();
			state_ = gameOver;
			delete pirateShip_;
			pirateShip_ = nullptr;
			return;
		}
		std::cout << "\nPress enter to continue.\n";
		getchar();
		break;
	case 2:
		std::cout << "All hands, make full sail!\n";
		std::cout << "The pirate ship shoots as you attempt to flee, and hits you with " << pirateShip_->Shoot() << " damage.\n";
		if (player_->Hit(pirateShip_->Shoot()))
		{
			std::cout << "The pirates defeated you,\nthey laugh and sing while you and your crew sink to the bottom of the ocean!\n";
			std::cout << "\nPress enter to continue.\n";
			getchar();
			state_ = gameOver;
			delete pirateShip_;
			pirateShip_ = nullptr;
			return;
		}
		if (player_->Flee(pirateShip_))
		{
			std::cout << "You succesfully manage to outrun the pirate ship!\n";
			std::cout << "\nPress enter to continue on your journey.\n";
			getchar();
			state_ = onSea;
			delete pirateShip_;
			pirateShip_ = nullptr;
			return;
		}
		std::cout << "You were unable to outrun the pirate ship, and you remain in battle.\n";
		std::cout << "\nPress enter to continue.\n";
		getchar();
		break;
	case 3:
		std::cout << "You realize that fighting pirates is scary, and cowardly wave the white flag!\n";
		std::cout << "While you sit in shame, the pirates help themselves to all your cargo,\nwhat they can't carry they throw overboard.\n";
		std::cout << "\nPress enter to continue on your journey.\n";
		getchar();
		state_ = onSea;
		delete pirateShip_;
		pirateShip_ = nullptr;
		break;
	default:
		break;
	}

}

void Game::GameOver()
{
	system("cls");
	std::cout << "Your travels have come to an early end.\n";
	int score = player_->GetMoney();
	std::cout << "With a fortune of " << score << " gold pieces, ";
	if (score < 1000)
		std::cout << "you were the worst trader in history,\nand your name will forever be synonymous with failure.\n";
	else if (score < 100000)
		std::cout << "you were on your way to become a descent trader.\n";
	else if (score < 500000)
		std::cout << "you were a wealthy trader known by many.\n";
	else if (score < 900000)
		std::cout << "you were a cunning, world renowned trader.\n";
	else
		std::cout << "you were a ruthless, and one of the most whealthiest traders in recent history.\n";
	getchar();
	state_ = exit;
}

void Game::GameWon()
{
	system("cls");
	std::cout << "Well done traveller, you succeeded in your goal of collecting 1,000,000 gold pieces.\n";
	std::cout << "You have become the wealthiest trader in history, feared by merchants and pirates alike.\n";
	std::cout << "History shall forever remember you, and your grand fortune of " << player_->GetMoney() << " gold pieces.\n";
	getchar();
	state_ = exit;
}

void Game::Cheat()
{
	system("cls");
	std::cout << "You have found the answer to the Ultimate Question of Life, the Universe, and Everything!\n";
	std::cout << "To continue your frivolous quest for fame and fortune seems pointless now.\n\n";
	std::cout << "Therefore you are granted 1,000,000 gold pieces and win the game.\n";
	getchar();
	player_->SetMoney(player_->GetMoney() + goal_);
	state_ = gameWon;
}
