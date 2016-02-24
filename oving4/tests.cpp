#include "tests.h"
#include <iostream>
#include "utilities.h"
#include <cmath>
#include <iomanip>

void incrementByValueNumTimes(int *startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
}


void testPart1()
{
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimes(&v0, increment, iterations);

	int left = 2, right = 5;
	printf("Left: %d, right: %d\n", left, right); // Lei av cout nå...
	swapNumbers(left, right);
	printf("Left: %d, right: %d\n", left, right);

	std::cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< std::endl;
}

// 2a
void testPart2() {
	// 2b
	const size_t size = 20;
	int percentages[size];

	arr::randomizeArray(percentages, size);
	arr::printArray(percentages, size);

	swapNumbers(percentages[0], percentages[1]);
	arr::printArray(percentages, size);

	std::cout << "Feil median: " << arr::medianOfArray(percentages, size) << std::endl;

	arr::sortArray(percentages, size);
	arr::printArray(percentages, size);

	std::cout << "Median: " << arr::medianOfArray(percentages, size) << std::endl;
	// Får forskjellig median, fordi median _må_ ta inn sortert tabell
}



// 4h
// Blir dumt å copy-paste; endrer average-greia til en funksjon
void printAverageGrade(char *grades, size_t size, const size_t numGrades) {
	unsigned int *gradeCount = new unsigned int[numGrades]; // Index 0:A, 1:B ... 5:F
	float average = 0;

	for (size_t i = 0; i < numGrades; i++) {
		unsigned int count = countOccurencesOfCharacter(grades, size, 'A' + i);
		gradeCount[i] = count;
		average += count*(i + 1); // Adderer vektet verdi for karakter. +1 fordi oppg. sa A=1, mens index i for A er 0
	}
	average /= size;
	char grade = 'A' + round(average) - 1; // Bruker 'A' som offset i ascii-tabellen, og trekker fra 1 fra average fordi oppg. sa A=1
	std::cout << "Snittkarakter: " << std::fixed << std::setprecision(1) << average << " (" << grade << ")" << std::endl;

	delete[] gradeCount;
}

// 4a
void testPart3() {
	// 4b
	const size_t size = 8; 
	char grades[size + 1]; // +1 for \0
	grades[size] = '\0';

	// 4d
	randomizeCString(grades, size, 'A', 'F');

	// 4e
	std::cout << "Grades: " << grades << std::endl;

	// 4h
	const size_t numGrades = 6; // 6='F'-'A'+1
	printAverageGrade(grades, size, numGrades);

	// 4i
	const size_t fiveYearSize = 8*5;
	char fiveYearGrades[fiveYearSize + 1]; // +1 for \0
	fiveYearGrades[fiveYearSize] = '\0';

	randomizeCString(fiveYearGrades, fiveYearSize, 'A', 'E');
	std::cout << "Five year grades: " << fiveYearGrades << std::endl;
	printAverageGrade(fiveYearGrades, fiveYearSize, numGrades);

	// E eller F som limit her? 
	// Usikker på om E kun gjelder for tilfeldig genererte karakterer
	readInputToCString(fiveYearGrades, fiveYearSize, 'A', 'E');
	std::cout << "Five year grades from user input: " << fiveYearGrades << std::endl;
	printAverageGrade(fiveYearGrades, fiveYearSize, numGrades);
}