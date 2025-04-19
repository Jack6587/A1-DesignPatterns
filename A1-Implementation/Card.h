#ifndef CARD_H
#define CARD_H
#include <string>

class Game;
class Player;

class Card {
public:
	enum CardType {
		Cannon, Chest, Key, Sword, Hook, Oracle,
		Map, Mermaid, Kraken
	};

	virtual ~Card() {}

	virtual void play(Game& game, Player& player) = 0;

	virtual CardType type() const;
	virtual std::string str() const;
	virtual int getValue() const;
	virtual void willAddToBank(Game& game, Player& player) = 0;

protected:
	int value;
	std::string name;
	CardType cardType;
	std::string ability;
};

#endif //CARD_H