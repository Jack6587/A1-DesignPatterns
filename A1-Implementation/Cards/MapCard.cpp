#include "MapCard.h"
#include "../Game.h"
#include <iostream>

MapCard::MapCard(int cardValue) {
	name = "Map";
	value = cardValue;
	cardType = Card::Map;
}

void MapCard::play(Game& game, Player& player) {
	std::cout << "Draw 3 cards from the discard and pick one to add to the play area:\n";
	CardCollection& discardCards = game.getDiscardPile().getCards();
	CardCollection drawnCards;

	if (discardCards.size() < 3) {
		std::cout << "Not enough cards in the discard pile!\n";
		return;
	}

	for (int i = 0; i < 3; i++) {
		Card* card = discardCards.back();
		discardCards.pop_back();
		drawnCards.push_back(card);
		std::cout << "(" << (i + 1) << ")" << card->str() << "\n";
	}

	int choice = 0;
	while (choice < 1 || choice > 3) {
		std::cout << "Which card do you pick?\n";
		std::cin >> choice;
	}

	Card* chosenCard = drawnCards[choice-1];
	player.playCard(chosenCard, game);
	drawnCards.erase(drawnCards.begin() + (choice - 1));

	for (Card* card : drawnCards){
		game.getDiscardPile().addCard(card);
	}
}

void MapCard::willAddToBank(Game& game, Player& player) {

}