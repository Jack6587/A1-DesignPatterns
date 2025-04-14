#include "MapCard.h"
#include <iostream>

MapCard::MapCard(int cardValue) {
	name = "Map";
	value = cardValue;
	cardType = Card::Map;
}

void MapCard::play(Game& game, Player& player) {

}

void MapCard::willAddToBank(Game& game, Player& player) {

}