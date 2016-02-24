#include "utilities.h"
#include <iostream>
#include <random>

namespace random {

int modernRandomWithLimits(int low, int high) {
	static std::random_device device;
	static std::mt19937 generator(device());
	std::uniform_int_distribution<int> uniform(low, high);
	return uniform(generator);
}

}

void swapNumbers(int &left, int &right) {
	int temp = left;
	left = right;
	right = left;
}

namespace arr {
// 2c
void printArray(int *arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

// 2d
void randomizeArray(int *arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = random::modernRandomWithLimits(0, 100);
	}
}

// 3a
// Sorter stigende, bubble-aktig insertion sort
void sortArray(int *arr, size_t size) {
	for (size_t i = 1; i < size; i++)
	{
		int current = i;
		while (arr[current] < arr[current - 1]) {
			swapNumbers(arr[current], arr[current - 1]);
			current--;
			if (current == 0) {
				break;
			}
		}
	}
}

// 3b
float medianOfArray(int *arr, size_t size) {
	size_t half = size / 2 - 1; // Trekk fra 1 pga 0-indeksert

	if (size % 2) {
		// Odde størrelse; har et midtpunkt
		return arr[half];
	}
	else {
		// Like størrelse; må gi gjennomsnitt av sentrum
		return (arr[half] + arr[half + 1]) / 2.f;
	}
}
}

// 4c
void randomizeCString(char *string, size_t size, char lower, char upper) {
	// Må ha samme casing, fordi jeg bruker tallverdiene dems som random limits
	// pga ascii-tabellen er sammenhengende innenfor samme casing.
	lower = toupper(lower);
	upper = toupper(upper);

	for (size_t i = 0; i < size; i++)
	{
		string[i] = random::modernRandomWithLimits(lower, upper);
	}
}

// 4f
void readInputToCString(char *tabell, size_t numInputs, char lower, char upper) {
	// La til numInputs, fordi oppgaven sa bare "bestemt antall tegn"
	lower = toupper(lower);
	upper = toupper(upper);

	size_t count = 0;
	char in;
	while (count < numInputs) {
		std::cout << "Skriv in tegn (" << numInputs - count << " gjenstår): ";
		std::cin >> in;
		in = toupper(in);

		if (in >= lower && in <= upper) {
			tabell[count] = in;
			count++;
		}
		else {
			std::cout << "Ugyldig input! Kun tegn mellom " << lower << " og " << upper << " er tillatt." << std::endl;
		}
	}
}

// 4g
unsigned int countOccurencesOfCharacter(const char *string, size_t size, char character) {
	// Trenger strengt tatt ikke å ta inn størrelsen på strengen om den er 0-terminert
	unsigned int count = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (string[i] == character) {
			count++;
		}
	}
	return count;
}
