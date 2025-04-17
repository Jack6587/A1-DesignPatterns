#include <iostream>
#include "Card.h"

Card::CardType Card::type() const {
	return cardType;
}

std::string Card::str() const {
	return name + "(" + std::to_string(value) + ")";
}

int Card::getValue() const {
	return value;
}

void Card::willAddToBank(Game& game, Player& player) {
	// base implementation (does nothing for most cards - overridden in Key and Chest classes)
}