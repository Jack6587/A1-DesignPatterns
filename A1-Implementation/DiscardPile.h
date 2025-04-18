#pragma once
#include "CardCollection.h"

class DiscardPile {
public:
	void addCard(Card* card);
	void addCards(CardCollection& cardSet);
	CardCollection& getCards();
	Card* drawCard();

private:
	CardCollection cards;
};