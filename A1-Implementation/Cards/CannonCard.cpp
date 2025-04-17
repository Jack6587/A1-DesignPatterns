#include "CannonCard.h"
#include <iostream>

CannonCard::CannonCard(int cardValue) {
	name = "Cannon";
	value = cardValue;
	cardType = Card::Cannon;
}

void CannonCard::play(Game& game, Player& player) {

}