#include "PlayArea.h"
#include "Card.h"
#include <iostream>

void PlayArea::toString() {
	for (Card* card : cards) {
		std::cout << card->str() << std::endl;
	}
}

void PlayArea::addCard(Card* card) {
	cards.push_back(card); // adds item to end of the vector
}

CardCollection& PlayArea::getCards() {
	return cards;
}

// clears all cards from the play area - used for player busts of an end of turn
void PlayArea::clear() {
	cards.clear(); // empties the vector of cards
}