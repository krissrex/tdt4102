#pragma once

namespace mastermind {
	// Antall tegn i koden
	const unsigned int SIZE = 4;
	// Antall forskjellige bokstaver
	const unsigned int LETTERS = 6;
	// Antall fors�k p� � gjette koden
	const unsigned int ATTEMPTS = 7;

	void playMasterMind();
}