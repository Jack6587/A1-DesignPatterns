#include "MermaidCard.h"
#include <iostream>

MermaidCard::MermaidCard(int cardValue) {
	name = "Mermaid";
	value = cardValue;
	cardType = Card::Mermaid;
}

void MermaidCard::play(Game& game, Player& player) {

}

void MermaidCard::willAddToBank(Game& game, Player& player) {

}