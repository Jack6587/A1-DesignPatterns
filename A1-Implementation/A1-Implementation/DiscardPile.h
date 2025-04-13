#include "CardCollection.h"

class DiscardPile {
public:
	void addCard(Card* card);
	void addCards(CardCollection& cardSet);

private:
	CardCollection cards;
};