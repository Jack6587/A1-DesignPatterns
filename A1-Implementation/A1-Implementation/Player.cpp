#include "Player.h"
#include "Deck.h"
#include <iostream>

Player::Player() {
	std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally",
	"Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10]; // sets a random name in the constructor
	_totalScore = 0; // score starts at 0
}

void Player::pickUpCard(Deck& deck) {
	Card* card = deck.drawCard();
	if (card) {
		playCard(card); // now, when player picks up a card, it automatically plays the card (which also adds to the play area)
	}
}

void Player::moveToBank(Card* card) {
	_bank.addCard(card);
}

void Player::playCard(Card* card) {
	_playArea.addCard(card);

	if (isBust()) {
		CardCollection& discardCards = _playArea.getCards();
		for (Card* card : discardCards) {
			_discardPile.addCard(card);
		}

		_playArea.clear();
	}
}

bool Player::isBust() {

}

std::string Player::getName() const {
	return _name;
}

int Player::getTotalScore() const {
	return _totalScore;
}

void Player::printCards(const CardCollection& cards, const std::string& cardArea){
	std::cout << cardArea << ":\n"; // output the area name, such as "Deck"

	for (Card* card : cards) {
		std::cout << card->str() << std::endl; // outputs each card from the collection
	}
} 