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
	CardCollection& opponentBank = game.getOpponent()->getBank().getCards();
	CardCollection highestCards;

	for (Card* card : opponentBank) {
		bool replaced = false;
		
		for (int i = 0; i < highestCards.size(); i++) {
			if (highestCards[i]->type() == card->type() {

			}
		}

	}
}

void CannonCard::willAddToBank(Game& game, Player& player) {
	
}