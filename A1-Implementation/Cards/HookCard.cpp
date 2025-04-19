#include "HookCard.h"
#include "../Game.h"
#include <iostream>

HookCard::HookCard(int cardValue) {
	name = "Hook";
	value = cardValue;
	cardType = Card::Hook;
}

void HookCard::play(Game& game, Player& player) {
	CardCollection& playerBank = player.getBank().getCards();
	CardCollection highestCards;

	for (Card* card : playerBank) {
		bool replaced = false;

		for (int i = 0; i < highestCards.size(); i++) {
			if (highestCards[i]->type() == card->type()) {
				if (card->getValue() > highestCards[i]->getValue()) {
					highestCards[i] = card;
				}
				replaced = true;
				break;
			}
		}

		if (!replaced) {
			highestCards.push_back(card); // adds a new type of card to highest cards (should only be added if there is no matching type/suit)
		}
	}

	std::cout << "Select a highest-value card from any of the suits in your Bank: " << std::endl;
	for (int i = 0; i < highestCards.size(); i++) {
		std::cout << (i + 1) << highestCards[i]->str() << std::endl; // outputs each card from highest cards collection (determined by its size)
	}

	int choice = 0;
	while (choice < 0 || choice >= highestCards.size()) {
		std::cout << "Which card do you pick? ";
		std::cin >> choice;
	}

	Card* selectedCard = highestCards[choice - 1]; // get the chosen card based on input (- 1 to account for for loop)
	player.getBank().removeCard(selectedCard); // remove card from player's bank
	player.playCard(selectedCard, game); // play the card from the player
}

void HookCard::willAddToBank(Game& game, Player& player) {

}