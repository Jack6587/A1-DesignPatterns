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

private:
	CardCollection deck; // stores all cards in the main deck
	int currentRound;
	int currentTurn;
	Player* currentPlayer;
	Player* player1;
	Player* player2; // using pointers for players for easy rotation
	static Game* instance;

};