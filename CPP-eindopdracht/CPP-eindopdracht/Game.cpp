#include "Game.h"
#include <iostream>

Game::Game()
{
	ships_ = new Ships();
	ports_ = new Ports();
	startLocation_ = new Location(ports_, ships_, "Roatan");
	player_ = new Player(ships_->GetShip(0), startLocation_);
	state_ = 0;
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
	int choice = 99;
	while (choice != 99)
	{
		switch (state_)
		{
		case 0:
			InPort();
			break;
		case 1:
			OnSea();
			break;
		case 2:
			InBattle();
			break;
		case 3:
			GameOver();
			break;
		case 4:
			GameWon();
			break;
		default:
			break;
		}
		getchar();
	}
}

void Game::InPort()
{
	std::cout << "Options:\n";
	std::cout << "\t1: Buy goods\n";
	std::cout << "\t2: Sell goods\n";
	std::cout << "\t3: Buy cannons\n";
	std::cout << "\t4: Sell cannons\n";
	std::cout << "\t5: Buy ship\n";
	std::cout << "\t6: Fix ship\n";
	std::cout << "\t7: Depart\n";
	std::cout << "\t8: Retire\n";
	int choice = 0;
	while(choice < 0 || choice > 8)
	{
		std::cout << "\nInput a valid number: ";
		std::cin >> choice;
		getchar();
	}
	switch(choice)
	{
	case 1:
		player_->BuyGoods();
		break;
	case 2:
		
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	default:
		break;
	}
}

void Game::OnSea()
{
}

void Game::InBattle()
{
}

void Game::GameOver()
{
}

void Game::GameWon()
{
}
