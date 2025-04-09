#include "Player.h"
#include <iostream>

Player::Player() {
	std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally",
	"Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10]; // sets a random name in the constructor
	_totalScore = 0; // score starts at 0
}

void Player::pickUpCard() {

}

void Player::moveToBank(Card* card) {

}

void Player::playCard(Card* card, CardCollection* deck) {

}

void Player::isBust() {

}

void Player::printCards(const CardCollection& cards, const std::string& cardArea){
	std::cout << cardArea << ":\n"; // output the area name, such as "Deck"

	for (Card* card : cards) {
		std::cout << card->str() << std::endl; // outputs each card from the collection
	}
} 