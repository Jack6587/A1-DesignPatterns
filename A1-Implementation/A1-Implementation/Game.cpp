#include "Game.h"
#include <iostream>

Game* Game::instance = nullptr; // static pointer to the instance of the Game class, ensuring only one instance is created and 

Game::Game() {
	currentRound = 1;
	currentTurn = 1;
	player1 = nullptr;
	player2 = nullptr;
	currentPlayer = nullptr;
}

Game::~Game() {
	delete player1;
	delete player2;
	instance = nullptr; // instance needs to be set to nullptr -
	// if a new game is started, it will still point to the old 
	// address and then a new instance cannot be made
}

void Game::startGame() {
	createDeck(); // set up deck for first time
	shuffleDeck();
	initialisePlayers(); // initialise new players
	std::cout << "Starting Dead Man's Draw++!" << std::endl;

	playRound(); // starts the first round
}

void Game::endGame() {

	outputScores();
	// if(player1.totalScore > player2.totalScore){return player1 wins!
}

void Game::playRound() {
	std::cout << "--- Round " << currentRound << ", Turn " << currentTurn << " ---" << std::endl;
	drawCard();

	while (!currentPlayer->isBust()) {
		if (!promptPlayerToDraw()) {
			currentPlayer->endTurn();
			break;
		}
		else {
			drawCard();
		}
	}

	switchPlayer();
}

void Game::createDeck() {
	_deck = new Deck();
}

void Game::shuffleDeck(CardCollection& cards) {

}

void Game::initialisePlayers() {
	player1 = new Player();
	player2 = new Player();

	currentPlayer = player1;
}

void Game::drawCard() {

}

bool Game::promptPlayerToDraw() {
	std::string input;
	std::cout << "Draw again? (y/n): ";
	std::cin >> input;

	return input == "y" || input == "Y";
}

void Game::outputScores() {
	// player1->printCards();
	std::cout << "Score: " << std::endl;

	// player2->printCards();
}

void Game::switchPlayer() {
	if (player1 == currentPlayer) { // switch player based on who just made their turn
		currentPlayer = player2;
	}
	else {
		currentPlayer = player1;
	}

	currentTurn++; // increment turn after player is switched

	if (currentTurn % 2 == 0) { // current turn should be even if both players have made their turn
		currentRound++; // increment round if both players have had a turn
	}
}

void Game::gameOver() {

}

Game* Game::getInstance() {
	if (instance == nullptr) { // if pointer (instance) hasn't been initialised
		instance = new Game(); // creates an instance
	}
	return instance;
}