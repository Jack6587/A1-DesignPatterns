#include "Deck.h"
#include <iostream>

bool Deck::isEmpty() {
	return _cards.empty();
}

Card* Deck::drawCard() {
	Card* topCard = _cards.back();
	_cards.pop_back();
	return topCard;
}