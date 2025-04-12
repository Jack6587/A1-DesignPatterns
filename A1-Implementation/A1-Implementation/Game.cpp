#include "Game.h"

Game* Game::instance = nullptr; // static pointer to the instance of the Game class, ensuring only one instance is created and 

Game::Game() {
	currentRound = 1;
	currentTurn = 1;
	player1 = nullptr;
	player2 = nullptr;
	currentPlayer = nullptr;
}

Game::~Game() {

}

void Game::startGame() {

}

void Game::endGame() {

}

void Game::createDeck() {

}

void Game::shuffleDeck(CardCollection& cards) {

}

void Game::initialisePlayers() {

}

void Game::drawCard() {

}

void Game::promptPlayerToDraw() {

}

void Game::outputScores() {

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

}