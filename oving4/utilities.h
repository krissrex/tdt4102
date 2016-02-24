#pragma once

#include <cstdlib>
#include <utility>

namespace random {
inline int randomWithLimits(int low, int high) {
	return std::rand() % (high - low) + low;
}

int modernRandomWithLimits(int low, int high);

}

void swapNumbers(int &left, int &right);
/*
eventuelt
void swapNumbers(int *left, int *right) {
int temp = *left;
*left = *right;
*right = temp;
}
*/

namespace arr {
void printArray(int *arr, size_t size);
void randomizeArray(int *arr, size_t size);

void sortArray(int *arr, size_t size);
float medianOfArray(int *arr, size_t size);
}

void readInputToCString(char *tabell, size_t numInputs, char lower, char upper);
void randomizeCString(char *string, size_t size, char lower, char upper);
unsigned int countOccurencesOfCharacter(const char *string, size_t size, char character);

