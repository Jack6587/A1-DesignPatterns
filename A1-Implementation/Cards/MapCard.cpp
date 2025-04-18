#include "MapCard.h"
#include "../Game.h"
#include "../Player.h"
#include "../PlayArea.h"
#include <iostream>

MapCard::MapCard(int cardValue) {
	name = "Map";
	value = cardValue;
	cardType = Card::Map;
}

void MapCard::play(Game& game, Player& player) {
	CardCollection& discardCards = game.getDiscardPile().getCards();
	CardCollection drawnCards;

	if (discardCards.empty()) {
		std::cout << "No cards in the discard pile!\n";
		return;
	}

	for (int i = 0; i < 3; i++) {
		Card* card = discardCards.back();
		discardCards.pop_back();
		drawnCards.push_back(card);
		player.getPlayArea().addCard(card);
		std::cout << card->str() << "\n";
	}

	int choice = 0;
	while (choice > drawnCards.size() || choice < 1) {
		std::cout << "Choose a card to play (1-3): ";
		std::cin >> choice;
	}

	Card* chosenCard = drawnCards[choice-1];
	player.playCard(chosenCard, game);
	drawnCards.erase(chosenCard);

	for (Card* card : drawnCards){
		game.getDiscardPile().addCard(card);
	}
}

void MapCard::willAddToBank(Game& game, Player& player) {

}