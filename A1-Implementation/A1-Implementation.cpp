// A1-Implementation.cpp : Defines the entry point for the application.
//

#include "A1-Implementation.h"
#include "Game.h"

using namespace std;

int main()
{
	Game* game = Game::getInstance();
	game->startGame();

	delete game;
	return 0;
}
