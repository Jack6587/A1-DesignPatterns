#pragma once
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "DiscardPile.h"

class Game {
public:
	Game(); //constructor
	~Game(); //destructor

	void startGame();
	void endGame();

	void createDeck();
	void shuffleDeck(); // SHUFFLE DECK NEEDS TO BE CHANGED
	void initialisePlayers();

	void playRound();

	void drawCard(); // for getting a card from the deck
	bool promptPlayerToDraw();
	void outputScores();
	void switchPlayer();
	void gameOver();
	DiscardPile& getDiscardPile();
	Deck* getDeck();

	static Game* getInstance(); // static so we can access this 
	// before game is instantiated (and is used to instantiate the game in the first place)

private:
	Deck* _deck; // stores all cards in the main deck
	DiscardPile _discardPile;
	int currentRound;
	int currentTurn;
	Player* currentPlayer;
	Player* player1;
	Player* player2; // using pointers for players for easy rotation
	static Game* instance; // game has just one pointer to its only instance

};