#include "Game.h"
#include "Card.h"
#include "Cards/CannonCard.h"
#include "Cards/ChestCard.h"
#include "Cards/KeyCard.h"
#include "Cards/SwordCard.h"
#include "Cards/HookCard.h"
#include "Cards/OracleCard.h"
#include "Cards/MapCard.h"
#include "Cards/MermaidCard.h"
#include "Cards/KrakenCard.h"
#include "GameTitle.h"
#include <algorithm>
#include <random>
#include <iostream>

Game* Game::instance = nullptr; // static pointer to the instance of the Game class, ensuring only one instance is created and 

Game::Game() {
	currentRound = 1;
	currentTurn = 1;
	player1 = nullptr;
	player2 = nullptr;
	currentPlayer = nullptr;
	_deck = nullptr;
}

Game::~Game() {
	delete player1;
	delete player2;
	instance = nullptr; // instance needs to be set to nullptr -
	// if a new game is started, it will still point to the old 
	// address and then a new instance cannot be made
	delete _deck;
	_deck = nullptr;
}

// Starts the game loop, displaying the title, creating and shuffling the deck and initialising players
// Plays up to five rounds in this implementation, or ends early if players reaches winning score (40)
void Game::startGame() {
	std::cout << GAME_TITLE << std::endl;
	createDeck(); // set up deck for first time
	shuffleDeck();
	initialisePlayers(); // initialise new players
	std::cout << "Starting Dead Man's Draw++!" << std::endl;

	while (currentRound <= 5) {
		playRound(); // plays 5 rounds
	}

	endGame();
}

// Ends the game, displaying final scores and determining a winner
void Game::endGame() {
	std::cout << "--- Game Over ---" << std::endl;
	outputScores();
	if (player1->getTotalScore() > player2->getTotalScore()) {
		std::cout << player1->getName() << " wins!\n";
	}
	else if (player2->getTotalScore() > player1->getTotalScore()) {
		std::cout << player2->getName() << " wins!\n";
	}
	else {
		std::cout << "Tie!" << std::endl;
	}
}

// Plays a round of the game. Each player here gets a turn (see the for loop), where they draw a card,
// check if they busted (in which case the turn ends and the player is switched), or are prompted to draw again, repeating until they bust or say no
// After each turn, the score is checked
void Game::playRound() {
	for (int i = 0; i < 2; i++) { // for loop that ensures each player gets a turn (one switch per iteration)
		std::cout << "--- Round " << currentRound << ", Turn " << currentTurn << " ---" << std::endl;
		std::cout << currentPlayer->getName() << "'s Turn" << std::endl;
		currentPlayer->printCards(currentPlayer->getBank().getCards(), "Bank");

		bool busted = drawCard(); // draw card returns true if bust and false if not to ensure the player turn ends if a player busts

		if (!busted) { // if player did not bust
			while (true) { // while no breaks occur
				if (!promptPlayerToDraw()) {
					currentPlayer->endTurn(*this); // end turn if player says no to draw again
					break;
				}
				if(drawCard()) { // if drawCard() called again returns true, break
					break;
				}
			}
		}

		currentPlayer->calculateScore();
		if (currentPlayer->getTotalScore() >= 40) { // check if score reached winning score
			endGame();
			return;
		}

		switchPlayer();
	}

	currentRound++; // after both players finish
}

// Creates a deck of 54 cards: 9 suits with 6 cards each
void Game::createDeck() {
	_deck = new Deck();

	for (int i = 2; i <= 7; i++) {
		_deck->addCard(new CannonCard(i));
		_deck->addCard(new ChestCard(i));
		_deck->addCard(new KeyCard(i));
		_deck->addCard(new SwordCard(i));
		_deck->addCard(new HookCard(i));
		_deck->addCard(new OracleCard(i));
		_deck->addCard(new MapCard(i));
		_deck->addCard(new MermaidCard(i + 2)); // Each mermaid card has higher value (+2) by default
		_deck->addCard(new KrakenCard(i));
	}
}

// randomly shuffle the deck using std::shuffle
void Game::shuffleDeck() {
	std::shuffle(_deck->getCards().begin(), _deck->getCards().end(), std::default_random_engine{}); // shuffles elements within the range of beginning to end of the deck randomly using random number generator
}

// Initialises two players, setting the currentPlayer to player1
void Game::initialisePlayers() {
	player1 = new Player();
	player2 = new Player();

	currentPlayer = player1;
}

// Draws one card from the deck. Returns true if the player busts or the deck is empty
bool Game::drawCard() {
	Card* card = _deck->drawCard();
	if (!card) {
		std::cout << "Deck is empty! Game over...\n";
		endGame();
		return true; // return true, ending the turn -> as seen in playRound() method
	}

	bool playerBust = currentPlayer->playCard(card, *this); // plays the card immediately
	currentPlayer->printCards(currentPlayer->getPlayArea().getCards(), "Play Area"); // output play area after card is played
	return playerBust; // returns true / false based on what playCard() returns - true if bust, false if no bust
}

// Prompts the current player to determine if they want to draw again - returns true if they want to draw
bool Game::promptPlayerToDraw() {
	std::string input;
	std::cout << "Draw again? (y/n): ";
	std::cin >> input;

	return input == "y" || input == "Y";
}

// Output both players' scores based on their banked cards
void Game::outputScores() {
	player1->printCards(player1->getBank().getCards(), "Bank");

	player2->printCards(player2->getBank().getCards(), "Bank");
}

// Switch current player to the other player, increment the turn counter
void Game::switchPlayer() {
	if (player1 == currentPlayer) { // switch player based on who just made their turn
		currentPlayer = player2;
	}
	else {
		currentPlayer = player1;
	}

	currentTurn++; // increment turn after player is switched
}

DiscardPile& Game::getDiscardPile() {
	return _discardPile;
}

Deck* Game::getDeck() {
	return _deck;
}

Player* Game::getOpponent() {
	if (currentPlayer == player1) {
		return player2;
	}
	else {
		return player1;
	}
}

Player* Game::getCurrentPlayer() {
	return currentPlayer;
}
 // Singleton accessor: ensures that only a single instance of the game exists. Returns it if it does, creates it if it doesn't
Game* Game::getInstance() {
	if (instance == nullptr) { // if pointer (instance) hasn't been initialised
		instance = new Game(); // creates an instance
	}
	return instance;
}