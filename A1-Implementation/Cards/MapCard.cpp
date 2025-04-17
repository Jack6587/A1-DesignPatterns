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

	for (int i = 0; i < 3; i++) {
		Card* card = discardCards.back();
		discardCards.pop_back();
		drawnCards.push_back(card);
		player.getPlayArea().addCard(card);
	}
}

void MapCard::willAddToBank(Game& game, Player& player) {

}