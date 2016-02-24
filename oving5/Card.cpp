#include "Card.h"

namespace cards {

	// Dette er dustete. Heller fjern default-constructoren...
	Card::Card() : invalid(true)
	{
	}

	Card::Card(Suit s, Rank r)
	{
		initialize(s, r);
	}


	Card::~Card()
	{
	}

	void Card::initialize(Suit s, Rank r)
	{
		suit = s;
		rank = r;
		invalid = false;
	}

	Suit Card::getSuit() const
	{
		return suit;
	}

	Rank Card::getRank() const
	{
		return rank;
	}

	std::string Card::toString() const
	{
		if (invalid) {
			return "Invalid card";
		}
		// Copy paste fra cards::toString(CardStruct card), i stedet for å lage en CardStruct først
		return rankToString(rank) + " of " + suitToString(suit);
	}

	std::string Card::toStringShort() const
	{
		// Copy-paste, samme som toString
		return suitToString(suit)[0] + std::to_string(rank);;
	}

}