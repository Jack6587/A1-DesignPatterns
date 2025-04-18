#include "KrakenCard.h"
#include "../CardCollection.h"
#include "../Game.h"
#include <iostream>

KrakenCard::KrakenCard(int cardValue) {
	name = "Kraken";
	value = cardValue;
	cardType = Card::Kraken;
}

void KrakenCard::play(Game& game, Player& player) {
	std::cout << "Draw 3 cards from the deck and play each:\n";
	CardCollection& deckCards = game.getDeck()->getCards();

	if (deckCards.size() < 3) {
		std::cout << "Not enough cards in the deck!\n";
		return;
	}

	for (int i = 0; i < 3; i++) {
		Card* card = deckCards.back();
		deckCards.pop_back();
		player.getPlayArea().addCard(card);
		std::cout << (i + 1) << card->str() << "\n";
		player.playCard(card, game);
	}
}

void KrakenCard::willAddToBank(Game& game, Player& player) {

}