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

void CannonCard::willAddToBank(Game& game, Player& player) {

}