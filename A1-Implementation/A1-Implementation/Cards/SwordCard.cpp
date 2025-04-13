#include "SwordCard.h"
#include "../Card.h"
#include <iostream>

SwordCard::SwordCard(int cardValue) {
	name = "Sword";
	value = cardValue;
	cardType = Card::Sword;
}

void SwordCard::play(Game& game, Player& player) {

}

void SwordCard::willAddToBank(Game& game, Player& player) {

}