#include "MermaidCard.h"
#include <iostream>

MermaidCard::MermaidCard(int cardValue) {
	name = "Mermaid";
	value = cardValue;
	cardType = Card::Mermaid;
}

void MermaidCard::play(Game& game, Player& player) {
	std::cout << "    No effect but Mermaids are worth more.\n";
}

void MermaidCard::willAddToBank(Game& game, Player& player) {

}