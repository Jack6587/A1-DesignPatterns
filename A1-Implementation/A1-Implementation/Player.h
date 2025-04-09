#pragma once

#include <string>
#include "Card.h"
#include "Game.h"

class Player {
public:
	Player();

	void pickUpCard();
	void moveToBank(Card* card); // card is a pointer - because it's always changing (unlike a reference)
	void playCard(Card* card, CardCollection* deck); // moves card to play area, removes it from the current provided deck
	
	void isBust();
	void accessBank();
	void displayBank();

private:
	std::string _name;
	int _totalScore;
	CardCollection _playArea;
	CardCollection _bank;
};