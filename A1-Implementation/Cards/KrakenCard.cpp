#include "KrakenCard.h"
#include "../CardCollection.h"
#include "../Game.h"
#include <iostream>

KrakenCard::KrakenCard(int cardValue) {
	name = "Kraken";
	value = cardValue;
	cardType = Card::Kraken;
}

// Allows the player to draw 3 cards from the deck and play each consecutively. Break if the plaer busts
// Notify player if not enough cards in the deck
void KrakenCard::play(Game& game, Player& player) {
	std::cout << "    Draw 3 cards from the deck and play each:\n";
	CardCollection& deckCards = game.getDeck()->getCards();

	for (int i = 0; i < 3; i++) {
		if (deckCards.empty()) {
			std::cout << "    Deck is empty! No more cards to draw" << std::endl;
			break;
		}

		std::cout << "(" << (i + 1) << ") ";
		bool bust = game.drawCard();

		if (bust) {
			break;
		}
	}
}

void KrakenCard::willAddToBank(Game& game, Player& player) {

}