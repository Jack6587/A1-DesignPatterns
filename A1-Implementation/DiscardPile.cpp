#include "DiscardPile.h"

void DiscardPile::addCard(Card* card) {
	_cards.push_back(card);
}

void DiscardPile::addCards(CardCollection& cards) {
	for (Card* card : cards) {
		cards.push_back(card);
	}
}

CardCollection& DiscardPile::getCards() {
	return _cards;
}

Card* DiscardPile::drawCard() {
	Card* topCard = _cards.back(); // gets the last item from the vector
	_cards.pop_back(); // removes last item from the vector
	return topCard;
}