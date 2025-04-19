#ifndef BANK_H
#define BANK_H
#include "CardCollection.h"
#include <string>

class Bank {
public:
	void toString();
	void addCard(Card* card);
	void addCards(CardCollection& cardSet);
	CardCollection& getCards();
	bool isEmpty() const;
	void removeCard(Card* card);

private:
	CardCollection cards;
};

#endif //BANK_H