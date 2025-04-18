#include "ChestCard.h"
#include "../Game.h"
#include <iostream>

ChestCard::ChestCard(int cardValue) {
	name = "Chest";
	value = cardValue;
	cardType = Card::Chest;
}

void ChestCard::play(Game& game, Player& player) {

}

void ChestCard::willAddToBank(Game& game, Player& player) {
	bool hasKeyCard = false;
	for (Card* card : player.getBank().getCards()) {
		if (card->type() == Card::Key) {
			hasKeyCard = true;
			break;
		}
	}
}