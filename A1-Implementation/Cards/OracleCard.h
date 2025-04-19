#ifndef ORACLE_CARD_H
#define ORACLE_CARD_H
#include "../Card.h"
#include <string>

class OracleCard : public Card {
public:
	OracleCard(int value);

	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};

#endif //ORACLE_CARD_H