#include "Blackjack.h"
#include <algorithm> // min
#include <iostream>

// Unnamed namespace for liten util-function i 5d
namespace {
	int askForAceValue()
	{
		int value = -1;
		while (!(value == 1 || value == 11))
		{
			std::cin >> value;
		}
		return value;
	}
}


namespace blackjack {

	Blackjack::Blackjack() : playerHand(0), dealerHand(0), playerCardsDrawn(0), dealerCardsDrawn(0)
	{
	}


	Blackjack::~Blackjack()
	{
	}

	bool Blackjack::isAce(cards::Card * card)
	{
		// Card-klassen har ingen public exposure av invalid. Satser på at kortet er valid.
		return card->getRank() == cards::Rank::ACE;
	}

	int Blackjack::getCardValue(cards::Card * card)
	{
		if (isAce(card))
		{
			return -1;
		}

		int cardValue = static_cast<int>(card->getRank());
		return std::min(cardValue, 10);
	}

	int Blackjack::getPlayerCardValue(cards::Card * card)
	{
		int value = getCardValue(card);
		if (value == -1)
		{
			std::cout << "Do you want your " << card->toString() << " to be 1 or 11?";
			value = askForAceValue();
		}
		return value;
	}

	int Blackjack::getDealerCardValue(cards::Card * card, int handValue)
	{
		int value = getCardValue(card);

		if (! isAce(card))
		{
			return value;
		}
		
		if (11 + handValue > 21)
		{
			return 1;
		}
		return 11;
	}

	bool Blackjack::askPlayerDrawCard()
	{
		char ans;
		std::cout << "Do you want to draw another card? (y/n)" << std::endl;
		std::cin >> ans;
		
		return ans == 'y' || ans == 'Y';
	}

	void Blackjack::drawInitialCards()
	{
		auto dealerCard = deck.drawCard();
		auto dealerCard2 = deck.drawCard();
		dealerCardsDrawn += 2;

		if (isAce(&dealerCard))
		{
			dealerHand += getCardValue(&dealerCard2);
			dealerHand += getDealerCardValue(&dealerCard, dealerHand);
		}
		else
		{
			dealerHand += getCardValue(&dealerCard);
			dealerHand += getDealerCardValue(&dealerCard2, dealerHand);
		}

		std::cout << "Dealer got " << dealerCard.toString() << std::endl;


		auto card = deck.drawCard();
		auto card2 = deck.drawCard();
		playerCardsDrawn += 2;
		
		std::cout << "You got " << card.toString() << " and " << card2.toString() << std::endl;
		auto val = getPlayerCardValue(&card);
		auto val2 = getPlayerCardValue(&card2);
		playerHand += val + val2;

	}

	bool Blackjack::playGame()
	{
		deck.shuffle();
		drawInitialCards();

		while (true)
		{
			std::cout << "Your hand has a total of " << playerHand << std::endl;

			// Lar ikke brukeren trekke et til om han har blackjack allerede
			bool draw = (playerHand < 21) ? askPlayerDrawCard() : false;

			if (draw)
			{
				auto card = deck.drawCard();
				std::cout << "You got " << card.toString() << std::endl;
				auto val = getPlayerCardValue(&card);
				playerHand += val;
			}
			
			if (playerHand > 21)
			{
				break;
			}

			if (dealerHand < 17)
			{
				auto card = deck.drawCard();
				auto val = getDealerCardValue(&card, dealerHand);
				dealerHand += val;
				std::cout << "The dealer drew another card" << std::endl;
			}
			else if (!draw)
			{
				// Brukeren ville ikke trekke, og dealer har over 17
				break;
			}


			if (dealerHand > 21)
			{
				break;
			}
		}
		
		// Sjekk om noen tapte

		if (playerHand > 21)
		{
			std::cout << "You busted!" << std::endl;
			return false;
		}

		if (dealerHand > 21)
		{
			std::cout << "The dealer busted!" << std::endl;
			return true;
		}

		// dealer vinner om det blir uavgjort
		return playerHand > dealerHand;
	}


}