#ifndef MERMAID_CARD_H
#define MERMAID_CARD_H
#include "../Card.h"
#include <string>

class MermaidCard : public Card {
public:
	MermaidCard(int value);

	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};

#endif MERMAID_CARD_H