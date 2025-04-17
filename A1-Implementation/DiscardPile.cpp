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