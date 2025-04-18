#include "Player.h"
#include "Deck.h"
#include "Game.h"
#include <iostream>
#include <set>
#include <map>

Player::Player() {
	std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally",
	"Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10]; // sets a random name in the constructor
	_totalScore = 0; // score starts at 0
}

void Player::moveToBank(Card* card) {
	_bank.addCard(card);
}

bool Player::playCard(Card* card, Game& game) {
	std::cout << getName() << "draws a " << card->str();
	_playArea.addCard(card);

	if (isBust()) {
		std::cout << "BUST! " << getName() << " loses all cards in play area.\n";
		CardCollection& discardCards = _playArea.getCards();
		for (Card* card : discardCards) {
			game.getDiscardPile().addCard(card); // each card from the play area gets moved to the shared discard pile
		}

		_playArea.clear();
		return true; // play area is cleared and true returned
	}

	card->play(game, *this); // otherwise, the card is played with its specific ability, using the game reference and this player
	printCards(getPlayArea().getCards(), "Play Area");
	return false;
}

void Player::endTurn(Game& game) {
	CardCollection& playedCards = _playArea.getCards();
	for (Card* card : playedCards) {
		card->willAddToBank(game, *this);
	}

	_bank.addCards(playedCards);

	_playArea.clear();
	printCards(getBank().getCards(), "Bank");
}

bool Player::isBust() {
	std::set<Card::CardType> cardTypes;

	for (Card* card : _playArea.getCards()) { // loop over play area cards
		Card::CardType type = card->type(); // get the type of the current card
		if (cardTypes.count(type)) { // determine if card type already exists (using count, from set)
			return true; // return true
		}
		cardTypes.insert(type); // otherwise, add to the caradTypes set for further checking
	}
	return false;
}

void Player::printCards(const CardCollection& cards, const std::string& cardArea) {
	std::cout << getName() << "'s " << cardArea << ":\n"; // output the area name, such as "Deck"

	for (Card* card : cards) {
		std::cout << card->str() << "\n"; // outputs each card from the collection
	}

	if (cardArea == "Bank") {
		calculateScore();
		std::cout << "| Score: " << getTotalScore() << std::endl;
	}
}

std::string Player::getName() const {
	return _name;
}

int Player::getTotalScore() const {
	return _totalScore;
}

void Player::calculateScore() {
	CardCollection highestCards;
	CardCollection& bankCards = _bank.getCards();

	for (Card* card : bankCards) {
		bool replaced = false;
		for (int i = 0; i < bankCards.size(); i++) {
			if (highestCards[i]->type() == card->type()) {
				if (highestCards[i]->getValue() < card->getValue()) {
					highestCards[i] = card;
				}
				replaced = true;
				break;
			}
		}

		if (!replaced) {
			highestCards.push_back(card);
		}
	}

	int score = 0;
	for (Card* card : highestCards) {
		score += card->getValue();
	}

	_totalScore = score;

}

PlayArea& Player::getPlayArea() {
	return _playArea;
}

Bank& Player::getBank() {
	return _bank;
}