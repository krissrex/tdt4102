/*
Kristian Rekstad
TDT4102 Prosedyre og objektorientert programmering
Vår 2016
Øving 5
*/

#include <iostream>
#include "cards.h"
#include "CardDeck.h"
#include "Blackjack.h"
#include <random>
#include <time.h>

using namespace cards;

int main() {
	CardStruct card;
	card.r = Rank::EIGHT;
	card.s = Suit::DIAMONDS;

	std::cout << suitToString(card.s) << std::endl; // diamonds
	std::cout << rankToString(card.r) << std::endl;	// eight
	std::cout << toString(card) << std::endl;		// eight of diamonds
	std::cout << toStringShort(card) << std::endl;	// d8

	// Seeder random for deck.shuffle
	srand(time(0));
	
	CardDeck deck;
	deck.print();
	std::cout << std::endl << std::endl;
	deck.shuffle();
	deck.print();
	std::cout << std::endl << std::endl;

	bool running = true;

	while (running)
	{
		blackjack::Blackjack blackj;
		std::cout << "You " << (blackj.playGame() ? "won" : "lost") << std::endl;

		char ans;
		std::cout << "Play again? (y/n)" << std::endl;
		std::cin >> ans;
		running = ans == 'y' || ans == 'Y';
	}
	
}