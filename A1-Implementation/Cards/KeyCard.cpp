#include "KeyCard.h"
#include "../Game.h"
#include <iostream>

KeyCard::KeyCard(int cardValue) {
	name = "Key";
	value = cardValue;
	cardType = Card::Key;
}

void KeyCard::play(Game& game, Player& player) {
	std::cout << "No immedate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank.\n";
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