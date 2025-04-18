#include "KeyCard.h"
#include "../Game.h"
#include <iostream>

KeyCard::KeyCard(int cardValue) {
	name = "Key";
	value = cardValue;
	cardType = Card::Key;
}

void KeyCard::play(Game& game, Player& player) {

}

void KeyCard::willAddToBank(Game& game, Player& player) {
	bool hasChestCard = false;
	for (Card* card : player.getBank().getCards()) {
		if (card->type() == Card::Chest) {
			hasChestCard = true;
			break;
		}
	}
}