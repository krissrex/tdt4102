#include "CardDeck.h"
#include <iostream>		// cout
#include <utility>		// swap
#include <algorithm>	// random_shuffle

namespace cards {

	CardDeck::CardDeck() : currentCardIndex(0)
	{
		// Holder styr på index i cards
		size_t index = 0;

		for (size_t suit = 0; suit < 4; suit++)
		{
			for (size_t rank = 2; rank <= 14; rank++)
			{
				// Bruker static_cast for å gjøre int til enum.
				// Litt "fragile", i tilfelle noen endrer enum-verdiene, men det funker greit nå
				this->cards[index] = Card(static_cast<Suit>(suit), static_cast<Rank>(rank));
				index++;
			}
		}
	}


	CardDeck::~CardDeck()
	{
	}

	void CardDeck::swap(int first, int second) 
	{
		std::swap(cards[first], cards[second]);
	}

	void CardDeck::shuffle()
	{
		// Burde ikke denne resette currentCardIndex?

		// Gøy at oppgavene bare trenger å bruke standardbiblioteket...
		std::random_shuffle(cards.begin(), cards.end());
	}

	void CardDeck::print() const 
	{
		// Burde ikke denne bruke currentCardIndex?
		for each (Card card in cards) 
		{
			std::cout << card.toString() << std::endl;
		}
	}

	void CardDeck::printShort() const 
	{
		for each (Card card in cards) 
		{
			std::cout << card.toStringShort() << std::endl;
		}
	}

	Card CardDeck::drawCard()
	{
		if (currentCardIndex == this->cards.size()) 
		{
			throw "No more cards";
		}
		return this->cards[currentCardIndex++];
	}

}