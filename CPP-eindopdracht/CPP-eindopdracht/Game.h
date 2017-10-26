#pragma once
#include "Ships.h"
#include "Ports.h"
#include "Location.h"
#include "Player.h"

class Game
{
public:
	Game();
	~Game();
	void StartGame();

private:
	static void Startup();
	void StartInfo() const;
	void GameLoop();
	void InPort();
	void OnSea();
	void InBattle();
	void GameOver();
	void GameWon();
	void Cheat();

	Ships* ships_;
	Ports* ports_;
	Location* startLocation_;
	Player* player_;
	
	int state_;
	int goal_;

	enum state
	{
		inPort,
		onSea,
		inBattle,
		gameOver,
		gameWon,
		theAnswer = 42,
		exit = 99
	};

	enum inPort
	{
		buyGoods = 1,
		sellGoods,
		buyCannons,
		sellCannons,
		buyShip,
		fixShip,
		depart,
		retire
	};
};

