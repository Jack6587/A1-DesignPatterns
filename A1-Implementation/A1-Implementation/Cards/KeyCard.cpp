#include "KeyCard.h"
#include <iostream>

KeyCard::KeyCard(int cardValue) {
	name = "Key";
	value = cardValue;
	cardType = Card::Key;
}

void KeyCard::play(Game& game, Player& player) {

}

void KeyCard::willAddToBank(Game& game, Player& player) {

}