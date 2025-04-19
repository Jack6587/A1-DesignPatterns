#ifndef CHEST_CARD_H
#define CHEST_CARD_H
#include "../Card.h"
#include <string>

class ChestCard : public Card {
public:
	ChestCard(int value);

	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};

#endif //CHEST_CARD_H