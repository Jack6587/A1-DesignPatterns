#include "OracleCard.h"
#include "../Game.h"
#include <iostream>

OracleCard::OracleCard(int cardValue) {
	name = "Oracle";
	value = cardValue;
	cardType = Card::Oracle;
}

void OracleCard::play(Game& game, Player& player) {
	Deck* deck = game.getDeck();

	if (deck->isEmpty()) {
		std::cout << "No cards in deck...\n";
		return;
	}
	Card* topCard = deck->getCards().back();
	std::cout << "The Oracle see a " << topCard->str() << "\n";
}

void OracleCard::willAddToBank(Game& game, Player& player) {

}