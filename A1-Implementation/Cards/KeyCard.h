#pragma once // temp
#include "../Card.h"
#include <string>

class KeyCard : public Card {
public:
	KeyCard(int value);

	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};