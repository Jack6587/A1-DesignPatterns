#include "KrakenCard.h"
#include "../Card.h"
#include <iostream>

KrakenCard::KrakenCard(int cardValue) {
	name = "Map";
	value = cardValue;
	cardType = Card::Map;
}

void KrakenCard::play(Game& game, Player& player) {

}

void KrakenCard::willAddToBank(Game& game, Player& player) {

}