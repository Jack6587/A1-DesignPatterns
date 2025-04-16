#include "SwordCard.h"
#include "../Game.h"
#include "../CardCollection.h"
#include <iostream>

SwordCard::SwordCard(int cardValue) {
	name = "Sword";
	value = cardValue;
	cardType = Card::Sword;
}

void SwordCard::play(Game& game, Player& player) {
	Player* opponent = game.getOpponent();
	Bank& opponentBank = opponent->getBank();

	if (opponentBank.isEmpty()) {
		std::cout << "No cards to steal from opponent's bank.\n";
		return;
	}

	Card* highestCard = nullptr;
	CardCollection& opponentCards = opponentBank.getCards();

	for (Card* card : opponentCards) {
		if (highestCard == nullptr || card->getValue() > highestCard->getValue()) { // changes highest card if the pointer is null or if the current card is greater than the current highest card
			highestCard = card;
		}
	}
}

void SwordCard::willAddToBank(Game& game, Player& player) {

}