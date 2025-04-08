#pragma once

#include <string>
#include "Card.h"

class Player {
public:
	Player();
	~Player();

	void pickUpCard();
	void moveToBank(Card* card); // card is a pointer - because it's always changing (unlike a reference)
	void playCard(Card* card, CardCollection* deck); // ? moves card to play area

	void isBust();
	void accessBank();
	void displayBank();

private:
	std::string name;
	int totalScore;
	CardCollection playArea;
	CardCollection bank;
};