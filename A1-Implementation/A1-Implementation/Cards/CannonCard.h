#pragma once // temp
#include "../Card.h"
#include <string>

class CannonCard : public Card {
public:
	CannonCard(int value);

	void play(Game& game, Player& player) override;
	Card::CardType type() const override;
	std::string str() const override;
	void willAddToBank(Game& game, Player& player) override;
};