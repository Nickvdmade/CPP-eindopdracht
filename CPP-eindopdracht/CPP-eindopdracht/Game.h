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

	Ships* ships_;
	Ports* ports_;
	Location* startLocation_;
	Player* player_;
	
	// 0: In Port
	// 1: On Sea
	// 2: In Battle
	// 3: Game Over
	// 4: Game Won
	int state_;
};

