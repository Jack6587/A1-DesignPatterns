#include "Bank.h"
#include <iostream>

void Bank::toString() {
	for (Card* card : cards) {
		std::cout << card << std::endl;
	}
}