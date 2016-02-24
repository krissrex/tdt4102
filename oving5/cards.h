#pragma once

#include <string>

namespace cards {

	// 1a
	enum Suit {
		CLUBS, DIAMONDS, HEARTS, SPADES
	};

	// 1b
	enum Rank {
		TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
	};

	// 1c
	std::string suitToString(Suit suit);
	// 1d
	std::string rankToString(Rank rank);

	// 2a
	struct CardStruct {
		Suit s;
		Rank r;
	};

	// 2b
	std::string toString(CardStruct card);
	// 2c
	std::string toStringShort(CardStruct card);
}