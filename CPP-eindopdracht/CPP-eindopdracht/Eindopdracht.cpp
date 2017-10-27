#include "RandomGenerator.h"
#include "Game.h"
#include <Windows.h>

using namespace std;

void main()
{
	HWND hwnd = GetConsoleWindow();
	if (hwnd != nullptr)
		MoveWindow(hwnd, 0, 0, 1000, 800, true);

	Game* game = new Game();
	game->StartGame();

	delete game;

	_CrtDumpMemoryLeaks();
}