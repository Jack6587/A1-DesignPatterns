#ifndef KRAKEN_CARD_H
#define KRAKEN_CARD_H
#include "../Card.h"
#include <string>

class KrakenCard : public Card {
public:
	KrakenCard(int value);

	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};

#endif //KRAKEN_CARD_H