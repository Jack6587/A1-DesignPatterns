#pragma once // temp
#include "../Card.h"
#include <string>

class HookCard : public Card {
public:
	HookCard(int value);

	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};