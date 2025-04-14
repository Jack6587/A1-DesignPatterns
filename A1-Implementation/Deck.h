#pragma once
#include "CardCollection.h"

class Deck {
public:
	Deck();

	void addCard(Card* card);
	Card* drawCard();
	bool isEmpty();
	CardCollection& getCards();

private:
	CardCollection _cards;
};