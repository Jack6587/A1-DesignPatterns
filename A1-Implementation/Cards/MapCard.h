#ifndef MAP_CARD_H
#define MAP_CARD_H
#include "../Card.h"
#include <string>

class MapCard : public Card {
public:
	MapCard(int value);

	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};

#endif //MAP_CARD_H