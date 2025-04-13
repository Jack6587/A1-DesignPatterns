#include "CardCollection.h"
#include <string>

class PlayArea {
public:
	void toString();
	void addCard(Card* card);
private:
	CardCollection cards;
};