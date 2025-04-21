#include "HookCard.h"
#include "../Game.h"
#include <iostream>
#include <map>

HookCard::HookCard(int cardValue) {
	name = "Hook";
	value = cardValue;
	cardType = Card::Hook;
}

// Lets the player choose the highest-value card from their bank to play. Display a list of cards (highest value)
// from each suit that belongs in their bank. Player selects one, which removes it from their bank and moves to the play area
void HookCard::play(Game& game, Player& player) {
	CardCollection& playerBank = player.getBank().getCards();
	std::map<Card::CardType, Card*> highestCards;

	for (Card* card : playerBank) {
		Card::CardType type = card->type();
		int value = card->getValue();

		if(highestCards.find(type) == highestCards.end() || value > highestCards[type]->getValue()){
			highestCards[type] = card;
		}
	}

	if (highestCards.empty()) {
		std::cout << "    No cards in your bank to choose from!" << std::endl;
		return;
	}

	CardCollection cardOptions;
	std::cout << "Select a highest-value card from any of the suits in your Bank: " << std::endl;
	int index = 1;
	for (auto& pair : highestCards) {
		std::cout << "(" << (index) << ")" << pair.second->str() << std::endl;
		cardOptions.push_back(pair.second);
		index++;
	}

	int choice = 0;
	while (choice < 1 || choice > static_cast<int>(cardOptions.size())) {
		std::cout << "Which card do you pick? ";
		std::cin >> choice;
	}

	Card* selectedCard = cardOptions[choice - 1]; // get the chosen card based on input (- 1 to account for for loop)
	player.getBank().removeCard(selectedCard); // remove card from player's bank
	player.playCard(selectedCard, game); // play the card from the player
}

void HookCard::willAddToBank(Game& game, Player& player) {

}