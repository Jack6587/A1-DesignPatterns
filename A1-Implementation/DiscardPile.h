#ifndef DISCARD_PILE_H
#define DISCARD_PILE_H
#include "CardCollection.h"

class DiscardPile {
public:
	void addCard(Card* card);
	void addCards(CardCollection& cardSet);
	CardCollection& getCards();
	Card* drawCard();

private:
	CardCollection _cards;
};

#endif //DISCARD_PILE_H