#pragma once
#include "CardCollection.h"
#include <string>

class Bank {
public:
	void toString();
	void addCard(Card* card);
	void addCards(CardCollection& cardSet);

private:
	CardCollection cards;
};