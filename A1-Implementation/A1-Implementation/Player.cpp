#include "Player.h"

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

void Player::accessBank() {

}

void Player::displayBank() {

}