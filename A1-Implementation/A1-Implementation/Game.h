#pragma once

#include <vector>
#include "Card.h"
#include "Player.h"

typedef std::vector<Card*> CardCollection;

class Game {
public:
	Game(); //constructor
	~Game(); //destructor

	void startGame();
	void endGame();

	void createDeck();
	void shuffleDeck(CardCollection cards);
	void initialisePlayers();

	void drawCard();
	void promptPlayerToDraw();
	void outputScores();
	void switchPlayer();
	void gameOver();
};