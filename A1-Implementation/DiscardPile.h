#pragma once
#include "CardCollection.h"

class DiscardPile {
public:
	void addCard(Card* card);
	void addCards(CardCollection& cardSet);
	CardCollection& getCards();

private:
	CardCollection cards;
};