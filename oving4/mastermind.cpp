#include "mastermind.h"
#include "utilities.h"
#include <iostream>
#include <algorithm>

namespace mastermind {
	unsigned int checkCharactersAndPosition(const char *code, const char *guess) {
		// bruker const for å ikke endre code eller guess med uvilje. Ikke viktig
		unsigned int numCorrect = 0;
		for (size_t i = 0; i < SIZE; i++) {
			if (code[i] == guess[i]) {
				numCorrect++;
			}
		}
		return numCorrect;
	}

	unsigned int checkCharacters(const char *code, const char *guess) {
		char codeChars[LETTERS] = { 0 };
		char guessChars[LETTERS] = { 0 };
		
		// Kunne brukt countOccurencesOfCharacter, men dette er mer effektivt
		
		for (size_t i = 0; i < SIZE; i++) {
			codeChars[code[i] - 'A']++;
			guessChars[guess[i] - 'A']++;
		}

		unsigned int correct = 0;
		for (size_t i = 0; i < LETTERS; i++) {
			correct += std::min(codeChars[i], guessChars[i]);
		}

		return correct;
	}

	void playMasterMind()
	{
		// 5b
		char code[SIZE+1];
		code[SIZE] = '\0';
		char guess[SIZE+1];
		guess[SIZE] = '\0';

		// 5c
		const char lower = 'A';
		const char upper = lower + LETTERS - 1;
		randomizeCString(code, SIZE, lower, upper);

		// 5d
		std::cout << "Riktig kode i mastermind: " << code << std::endl;

		// 5k
		bool playing = true;

		while (playing) {
			// 5j
			unsigned int tries = 1;

			// 5e
			std::cout << "MASTERMIND - Gjett koden" << std::endl;
			readInputToCString(guess, SIZE, lower, upper);

			// 5h
			unsigned int correct = checkCharactersAndPosition(code, guess);

			while (correct != SIZE && tries < ATTEMPTS) {
				unsigned int numCorrectChars = checkCharacters(code, guess);
				std::cout << std::endl << "Feil. Du gjettet " << numCorrectChars << " riktig" << (numCorrectChars==1?"":"e") << " tegn." << std::endl;
				std::cout << correct << " var på riktig plass." << std::endl;
				std::cout << "Du har " << ATTEMPTS - tries << " forsøk igjen." << std::endl;
				std::cout << "Prøv igjen: " << std::endl;
				readInputToCString(guess, SIZE, lower, upper);
				correct = checkCharactersAndPosition(code, guess);
				tries++;
			}

			std::cout << std::endl << "Du "<< (correct == SIZE ? "vant!" : "tapte.") << " Koden var " << code << std::endl;
	
			char retry = 'N';
			std::cout << "Vil du spille igjen? (J/N): ";
			// Clear og ignore for å tømme bufferet, i tilfelle man skriver f.eks. aaaaaaaaa
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin >> retry;
			retry = toupper(retry);
			if (retry != 'J') {
				playing = false;
			}

		}

		std::cout << "Ha det bra!" << std::endl;
	}

}
