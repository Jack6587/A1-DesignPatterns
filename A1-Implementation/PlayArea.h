#ifndef PLAY_AREA_H
#define PLAY_AREA_H
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

#endif // PLAY_AREA_H