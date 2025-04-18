#include "CannonCard.h"
#include "../Game.h"
#include <iostream>
#include <map>

CannonCard::CannonCard(int cardValue) {
	name = "Cannon";
	value = cardValue;
	cardType = Card::Cannon;
}

void CannonCard::play(Game& game, Player& player) {
	CardCollection& opponentBank = game.getOpponent()->getBank().getCards(); // get the cards in opponent's bank
	CardCollection highestCards; // make a new collection for highest cards to output / select from

	for (Card* card : opponentBank) { // iterate over all cards in the bank
		bool replaced = false;

		for (int i = 0; i < highestCards.size(); i++) { // check if any suit in new collection matches the current card's suit
			if (highestCards[i]->type() == card->type()) { // if they match
				if (card->getValue() > highestCards[i]->getValue()) { // check if card's value is higher than the suit's current value
					highestCards[i] = card; // if it is, make the card at position i be the new card and value
				}
				replaced = true; // replaced is true so that the next if statement is not entered. This should be triggered regardless so that another card of the same suit is not added to the collection
				break;
			}
		}

		if (!replaced) {
			highestCards.push_back(card); // if no card of this type was already found in our card collection, add it to the back
		}
	}

	for (Card* card : highestCards) {
		std::cout << card->str() << std::endl; // output each card collected (highest of each suit)
	}
}

void CannonCard::willAddToBank(Game& game, Player& player) {
	
}