#pragma once

#include "CardDeck.h"

namespace blackjack {

	class Blackjack
	{
	public:
		Blackjack();
		~Blackjack();

		// 7h
		// returnerer true om spilleren vinner
		bool playGame();


	private:		
		// Denne burde ligge i Card-klassen, eller ikke være en medlemsfunksjon...
		bool isAce(cards::Card* card);
		// 5c
		int getCardValue(cards::Card* card);
		// 5d
		int getPlayerCardValue(cards::Card* card);
		// 5e
		int getDealerCardValue(cards::Card* card, int handValue);
		// 5f
		bool askPlayerDrawCard();
		// 5g
		void drawInitialCards();


		cards::CardDeck deck;
		
		// Dette lukter Hand-klasse...
		unsigned int playerHand;
		unsigned int playerCardsDrawn;

		unsigned int dealerHand;
		unsigned int dealerCardsDrawn;

	};


}