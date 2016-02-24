#pragma once
#include "Card.h"
#include <array>

namespace cards {

	// 4a
	class CardDeck
	{
	public:
		// 4b
		CardDeck();
		~CardDeck();

		// 4d
		void print() const;
		// 4e
		void printShort() const;
		// 4g
		Card drawCard();
		// 4f
		void shuffle();

	private:
		// 4c
		void swap(int first, int second);
		
		std::array<Card, 52> cards;
		int currentCardIndex;
	};

}