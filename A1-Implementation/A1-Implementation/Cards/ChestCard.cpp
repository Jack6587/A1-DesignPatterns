#include "ChestCard.h"
#include "../Card.h"
#include <iostream>

ChestCard::ChestCard(int cardValue) {
	name = "Cannon";
	value = cardValue;
	cardType = Card::Cannon;
}

void ChestCard::play(Game& game, Player& player) {

}

Card::CardType ChestCard::type() const {
	return Card::Cannon;
}

std::string ChestCard::str() const {
	return name + "(" + std::to_string(value) + ")";
}

void ChestCard::willAddToBank(Game& game, Player& player) {

}