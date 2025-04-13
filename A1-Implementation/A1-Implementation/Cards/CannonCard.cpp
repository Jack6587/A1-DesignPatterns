#include "CannonCard.h"
#include "../Card.h"
#include <iostream>

CannonCard::CannonCard(int cardValue) {
	name = "Cannon";
	value = cardValue;
	cardType = Card::Cannon;
}

void CannonCard::play(Game& game, Player& player) {

}

Card::CardType CannonCard::type() const {
	return Card::Cannon;
}

std::string CannonCard::str() const {
	return name + "(" + std::to_string(value) + ")";
}

void CannonCard::willAddToBank(Game& game, Player& player) {

}