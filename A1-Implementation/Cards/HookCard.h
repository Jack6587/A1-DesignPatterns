#ifndef HOOK_CARD_H
#define HOOK_CARD_H
#include "../Card.h"
#include <string>

class HookCard : public Card {
public:
	HookCard(int value);

	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};

#endif //HOOK_CARD_H