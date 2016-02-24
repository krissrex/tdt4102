#pragma once
#include "cards.h"
#include <string>

namespace cards {

	class Card
	{
	public:
		Card();
		Card(Suit s, Rank r);
		~Card();
		void initialize(Suit s, Rank r);
		Suit getSuit() const; // Markerer som const, fordi funksjonen skal ikke endre card-objektet
		Rank getRank() const;
		std::string toString() const;
		std::string toStringShort() const;

	private:
		Rank rank;
		Suit suit;
		bool invalid;
	};

}