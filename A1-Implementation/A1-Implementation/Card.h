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

	virtual void play(Game& game, Player& player) const = 0;

	virtual CardType type() const = 0;

	virtual std::string str() const = 0;

	virtual void willAddToBank(Game&, Player& player) const = 0;
private:
	int _value;
	CardType _cardType;
	std::string _ability;
};