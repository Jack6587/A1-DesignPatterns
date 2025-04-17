#pragma once
#include <string>
#include "CardCollection.h"
#include "Card.h"
#include "Bank.h"
#include "PlayArea.h"
#include "Deck.h"
#include "DiscardPile.h"

class Player {
public:
	Player();

	void moveToBank(Card* card); // card is a pointer - because it's always changing (unlike a reference)
	bool playCard(Card* card, Game& game); // moves card to play area, removes it from the current provided deck
	void endTurn(Game& game);
	bool isBust();
	void printCards(const CardCollection& cards, const std::string& cardArea);

	std::string getName() const;
	int getTotalScore() const;
	PlayArea& getPlayArea();
	Bank& getBank();

private:
	std::string _name;
	int _totalScore;
	PlayArea _playArea;
	Bank _bank;
};