#include "CardCollection.h"
#include "Card.h"
#include "Player.h"

class Game {
public:
	Game(); //constructor
	~Game(); //destructor

	void startGame();
	void endGame();

	void createDeck();
	void shuffleDeck(CardCollection& cards);
	void initialisePlayers();

	void drawCard(); // for getting a card from the deck
	void promptPlayerToDraw();
	void outputScores();
	void switchPlayer();
	void gameOver();

	static Game* getInstance();

private:
	CardCollection _deck; // stores all cards in the main deck
	int currentRound;
	int currentTurn;
	Player* currentPlayer;
	Player* player1;
	Player* player2; // using pointers for players for easy rotation
	static Game* instance;

};