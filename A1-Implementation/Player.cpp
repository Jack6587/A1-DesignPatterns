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

// moves a single card into the player's bank
void Player::moveToBank(Card* card) {
	_bank.addCard(card);
}

// plays a card - adds it to the play area and checks if player busts
// if the player busts, move all cards to the discard pile and end turn
// otherwise, activate the card's ability and return false
bool Player::playCard(Card* card, Game& game) {
	std::cout << getName() << " draws a " << card->str() << std::endl;
	_playArea.addCard(card);

	if (isBust()) {
		std::cout << "BUST! " << getName() << " loses all cards in play area.\n";
		CardCollection& discardCards = _playArea.getCards();
		for (Card* card : discardCards) {
			game.getDiscardPile().addCard(card); // each card from the play area gets moved to the shared discard pile
		}

		_playArea.clear();
		game.getCurrentPlayer()->endTurn(game);
		return true; // play area is cleared and true returned - this returns back to drawCard() method (ultimately used in playRound for checking)
	}

	card->play(game, *this); // otherwise, the card is played with its specific ability, using the game reference and this player
	return false; // return false meaning the player did not bust, used for checking whether to continue prompting a player to draw
}

// end the player's turn by moving all cards from the play area to the bank, then clear play area
void Player::endTurn(Game& game) {
	CardCollection& playedCards = _playArea.getCards();
	for (Card* card : playedCards) {
		card->willAddToBank(game, *this); // used for cards like chest and key to check if they are also being banked
	}

	_bank.addCards(playedCards);

	_playArea.clear();
	printCards(getBank().getCards(), "Bank");
}

// checks if a bust occurs - where two cards have the same type in the play area
// returns true if busted, otherwise false
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

// prints a set of cards from a certain area (mainly used for bank and play area)
// if the bank is being displayed, get the score too
void Player::printCards(const CardCollection& cards, const std::string& cardArea) {
	std::cout << getName() << "'s " << cardArea << ":\n"; // output the area name, such as "Deck"

	for (Card* card : cards) {
		std::cout << "    " << card->str() << "\n"; // outputs each card from the collection
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

// calculates each player's score
// gets only the highest value of each suit with a map - where the key is the type and int is the highest value
// total of the highest cards combined
void Player::calculateScore() {
	std::map<Card::CardType, int> highestCards;

	for (Card* card : _bank.getCards()) {
		Card::CardType type = card->type();
		int value = card->getValue();

		if (highestCards.find(type) == highestCards.end() || value > highestCards[type]) { // if type does not appear yet, or card's value is higher than highest
			highestCards[type] = value;
		}
	}

	int score = 0;
	for (const auto& pair : highestCards) {
		score += pair.second; // value of the key-value pair in map (second)
	}

	_totalScore = score;

}

PlayArea& Player::getPlayArea() {
	return _playArea;
}

Bank& Player::getBank() {
	return _bank;
}