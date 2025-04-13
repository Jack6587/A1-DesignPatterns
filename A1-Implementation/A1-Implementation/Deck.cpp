#include "Deck.h"
#include "Cards/CannonCard.h"
#include "Cards/ChestCard.h"
#include "Cards/KeyCard.h"
#include "Cards/SwordCard.h"
#include "Cards/HookCard.h"
#include "Cards/OracleCard.h"
#include "Cards/MapCard.h"
#include "Cards/MermaidCard.h"
#include "Cards/KrakenCard.h"
#include <iostream>

Deck::Deck() {
    for (int i = 2; i <= 7; i++) {
        addCard(new CannonCard(i));
        addCard(new ChestCard(i));
        addCard(new KeyCard(i));
        addCard(new SwordCard(i));
        addCard(new HookCard(i));
        addCard(new OracleCard(i));
        addCard(new MapCard(i));
        addCard(new MermaidCard(i));
        addCard(new KrakenCard(i));
    }
}

void Deck::addCard(Card* card) {
	_cards.push_back(card);
}

bool Deck::isEmpty() {
	return _cards.empty();
}

Card* Deck::drawCard() {
	Card* topCard = _cards.back(); // gets the last item from the vector
	_cards.pop_back(); // removes last item from the vector
	return topCard;
}