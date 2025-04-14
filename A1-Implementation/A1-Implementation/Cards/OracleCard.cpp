#include "OracleCard.h"
#include <iostream>

OracleCard::OracleCard(int cardValue) {
	name = "Oracle";
	value = cardValue;
	cardType = Card::Oracle;
}

void OracleCard::play(Game& game, Player& player) {

}

void OracleCard::willAddToBank(Game& game, Player& player) {

}