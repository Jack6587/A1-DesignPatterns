#include "KrakenCard.h"
#include <iostream>

KrakenCard::KrakenCard(int cardValue) {
	name = "Kraken";
	value = cardValue;
	cardType = Card::Kraken;
}

void KrakenCard::play(Game& game, Player& player) {

}