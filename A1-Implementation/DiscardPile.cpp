#include "DiscardPile.h"

void DiscardPile::addCard(Card* card) {
	cards.push_back(card);
}

void DiscardPile::addCards(CardCollection& cards) {
	for (Card* card : cards) {
		cards.push_back(card);
	}
}

CardCollection& DiscardPile::getCards() {
	return cards;
}

Card* DiscardPile::drawCard() {
	Card* topCard = cards.back(); // gets the last item from the vector
	cards.pop_back(); // removes last item from the vector
	return topCard;
}