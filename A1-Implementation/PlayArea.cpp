#include "PlayArea.h"
#include <iostream>

void PlayArea::toString() {
	for (Card* card : cards) {
		std::cout << card << std::endl;
	}
}

void PlayArea::addCard(Card* card) {
	cards.push_back(card); // adds item to end of the vector
}

CardCollection& PlayArea::getCards() {
	return cards;
}

void PlayArea::clear() {
	cards.clear();
}