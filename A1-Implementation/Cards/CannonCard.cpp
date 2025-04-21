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
	std::map<Card::CardType, Card*> highestCards; // make a new collection for highest cards to output / select from

	for (Card* card : opponentBank) { // iterate over all cards in the bank
		Card::CardType type = card->type();
		int value = card->getValue();

		if (highestCards.find(type) == highestCards.end() || value > highestCards[type]->getValue()) {
			highestCards[type] = card;
		}
	}

	if (highestCards.empty()) { // if opponent has no cards
		std::cout << "    No cards in the opponent's bank!" << std::endl;
		return;
	}

	CardCollection cardOptions;
	std::cout << "Shoot the top card of any suit from the other player's Bank into the Discard Pile:" << std::endl;
	int index = 1;
	for (auto& pair : highestCards) { // for each pair in the map
		std::cout << "(" << index << ")" << pair.second->str() << std::endl; // outputs the choices
		cardOptions.push_back(pair.second);
		index++;
	}

	int choice = 0;
	while (choice < 1 || choice > static_cast<int>(cardOptions.size())) {
		std::cout << "Which card do you pick? ";
		std::cin >> choice;
	}

	Card* selectedCard = cardOptions[choice - 1];
	std::cout << "    You shoot the " << selectedCard->str() << " out of the other player's Bank\n";
	game.getOpponent()->getBank().removeCard(selectedCard);
	game.getDiscardPile().addCard(selectedCard);
}

void CannonCard::willAddToBank(Game& game, Player& player) {
	
}