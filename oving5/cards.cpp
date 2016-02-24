#include "cards.h"

std::string cards::suitToString(Suit suit)
{
	switch (suit)
	{
	case cards::CLUBS:		return "clubs";
	case cards::DIAMONDS:	return "diamonds";
	case cards::HEARTS:		return "hearts";
	case cards::SPADES:		return "spades";
	default:
		return std::string();
	}
}

std::string cards::rankToString(Rank rank)
{
	switch (rank)
	{
	case cards::TWO:	return "two";
	case cards::THREE:	return "three";
	case cards::FOUR:	return "four";
	case cards::FIVE:	return "five";
	case cards::SIX:	return "six";
	case cards::SEVEN:	return "seven";
	case cards::EIGHT:	return "eight";
	case cards::NINE:	return "nine";
	case cards::TEN:	return "ten";
	case cards::JACK:	return "jack";
	case cards::QUEEN:	return "queen";
	case cards::KING:	return "king";
	case cards::ACE:	return "ace";
	default:
		return std::string();
	}
}

std::string cards::toString(CardStruct card)
{
	return rankToString(card.r) + " of " + suitToString(card.s);
}

std::string cards::toStringShort(CardStruct card)
{
	// Alle enums har en tallverdi. Rank starter med TWO=2, THREE=3 osv.
	return suitToString(card.s)[0] + std::to_string(card.r);
}
