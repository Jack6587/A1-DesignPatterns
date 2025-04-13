#include "CardCollection.h"
#include <string>

class PlayArea {
public:
	void toString();
	void addCard(Card* card);
	CardCollection& getCards();
	void clear();

private:
	CardCollection cards;
};