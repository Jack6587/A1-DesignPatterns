#include "Bank.h"
#include "Card.h"
#include <iostream>

// output all cards in the bank
void Bank::toString() {
	for (Card* card : _cards) {
		std::cout << card->str() << std::endl;
	}
}

void Bank::addCard(Card* card) {
	_cards.push_back(card); // adds item to end of the vector using push_back
}

// adds multiple cards to the bank using a for loop
void Bank::addCards(CardCollection& cardSet) {
	for (Card* card : cardSet) {
		_cards.push_back(card);
	}
}

// returns true if bank has no cards
bool Bank::isEmpty() const {
	return _cards.empty();
}

CardCollection& Bank::getCards() {
	return _cards;
}

void Bank::removeCard(Card* card) {
	for (auto i = _cards.begin(); i != _cards.end(); i++) { // iterates over cards in bank - starting at the first card, loop until the end (if necessary)
		if (*i == card) { // once the value/card is reached - dereference the iterator to get the pointer
			_cards.erase(i); // remove and stop searching
			break;
		}
	}
}