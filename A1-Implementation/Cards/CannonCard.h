#ifndef CANNON_CARD_H
#define CANNON_CARD_H
#include "../Card.h"
#include <string>

class CannonCard : public Card {
public:
	CannonCard(int value);

	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};

#endif //CANNON_CARD_H