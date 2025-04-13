#include "CardCollection.h"

class Deck {
public:
	Deck();

	void addCard(Card* card);
	Card* drawCard();
	bool isEmpty();

private:
	CardCollection _cards;
};