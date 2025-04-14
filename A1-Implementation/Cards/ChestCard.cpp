#include "ChestCard.h"
#include <iostream>

ChestCard::ChestCard(int cardValue) {
	name = "Chest";
	value = cardValue;
	cardType = Card::Chest;
}

void ChestCard::play(Game& game, Player& player) {

}

void ChestCard::willAddToBank(Game& game, Player& player) {

}