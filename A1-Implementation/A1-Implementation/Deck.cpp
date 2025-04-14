#include "Deck.h"
#include <iostream>

Deck::Deck() {
}

void Deck::addCard(Card* card) {
	_cards.push_back(card); // adds the card to the end of the vector
}

bool Deck::isEmpty() {
	return _cards.empty();
}

Card* Deck::drawCard() {
	Card* topCard = _cards.back(); // gets the last item from the vector
	_cards.pop_back(); // removes last item from the vector
	return topCard;
}

CardCollection& Deck::getCards() {
	return _cards;
}