#include "HookCard.h"
#include "../Card.h"
#include <iostream>

HookCard::HookCard(int cardValue) {
	name = "Hook";
	value = cardValue;
	cardType = Card::Hook;
}

void HookCard::play(Game& game, Player& player) {

}

void HookCard::willAddToBank(Game& game, Player& player) {

}