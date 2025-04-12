#include <string>
#include "CardCollection.h"
#include "Card.h"
#include "Bank.h"
#include "PlayArea.h"
#include "Deck.h"

class Player {
public:
	Player();

	void pickUpCard(Deck& deck);
	void moveToBank(Card* card); // card is a pointer - because it's always changing (unlike a reference)
	void playCard(Card* card, CardCollection* deck); // moves card to play area, removes it from the current provided deck
	
	bool isBust();
	void printCards(const CardCollection& cards, const std::string& cardArea);

	std::string getName() const;

	int getTotalScore() const;

private:
	std::string _name;
	int _totalScore;
	PlayArea _playArea;
	Bank _bank;
};