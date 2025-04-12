#include "CardCollection.h"

class Deck {
public:
	Card* drawCard();
	bool isEmpty();

private:
	CardCollection _cards;
};