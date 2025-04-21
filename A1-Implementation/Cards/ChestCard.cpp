#include "ChestCard.h"
#include "../Game.h"
#include <iostream>

ChestCard::ChestCard(int cardValue) {
	name = "Chest";
	value = cardValue;
	cardType = Card::Chest;
}

void ChestCard::play(Game& game, Player& player) {
	std::cout << "    No immeduate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved into your Bank.\n";
}

void ChestCard::willAddToBank(Game& game, Player& player) {
	const CardCollection& movingToBank = player.getPlayArea().getCards(); // gets all cards that will be moving to bank
	bool hasKeyCard = false;
	for (Card* card : movingToBank) {
		if (card->type() == Card::Key) {
			hasKeyCard = true;
			break;
		}
	}

	if (hasKeyCard) {
		std::cout << "Chest and Key activated. Added ";
		int bankingCards = movingToBank.size(); // number of cards moving to bank to determine how many to be drawn from discard pile
		for (int i = 0; i < bankingCards; i++) {
			Card* card = game.getDiscardPile().drawCard();
			if (card) {
				player.getBank().addCard(card);
				std::cout << card->str();
			}
			else {
				std::cout << "    No cards left to draw from the discard pile!\n";
				break;
			}
		}
		std::cout << " to your Bank.\n";
	}
}