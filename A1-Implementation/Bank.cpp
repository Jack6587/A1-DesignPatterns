#include "Bank.h"
#include <iostream>

void Bank::toString() {
	for (Card* card : _cards) {
		std::cout << card << std::endl;
	}
}

void Bank::addCard(Card* card) {
	_cards.push_back(card); // adds item to end of the vector
}

void Bank::addCards(CardCollection& cardSet) {
	for (Card* card : cardSet) {
		_cards.push_back(card);
	}
}

bool Bank::isEmpty() const {
	return _cards.empty();
}

CardCollection& Bank::getCards() {
	return _cards;
}

void Bank::removeCard(Card* card) {
	for (auto i = _cards.begin(); i != _cards.end(); i++) { // iterates over cards in bank
		if (*i == card) {
			_cards.erase(i);
			break;
		}
	}
}