#include "Bank.h"
#include <iostream>

void Bank::toString() {
	for (Card* card : cards) {
		std::cout << card << std::endl;
	}
}

void Bank::addCard(Card* card) {
	cards.push_back(card); // adds item to end of the vector
}

void Bank::addCards(CardCollection& cardSet) {
	for (Card* card : cardSet) {
		cards.push_back(card);
	}
}