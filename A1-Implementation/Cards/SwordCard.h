#pragma once // temp
#include "../Card.h"
#include <string>

class SwordCard : public Card {
public:
	SwordCard(int value);

	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};