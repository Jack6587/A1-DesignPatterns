#include "Deck.h"
#include <iostream>

bool Deck::isEmpty() {
	return _cards.empty();
}

Card* Deck::drawCard() {
	Card* topCard = _cards.back(); // gets the last item from the vector
	_cards.pop_back(); // removes last item from the vector
	return topCard;
}