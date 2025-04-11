#include "PlayArea.h"
#include <iostream>

void PlayArea::toString() {
	for (Card* card : cards) {
		std::cout << card << std::endl;
	}
}