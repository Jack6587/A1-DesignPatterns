#pragma once // temp
#include "../Card.h"
#include <string>

class ChestCard : public Card {
public:
	ChestCard(int value);

	void play(Game& game, Player& player) override;
	Card::CardType type() const override;
	std::string str() const override;
	void willAddToBank(Game& game, Player& player) override;
};