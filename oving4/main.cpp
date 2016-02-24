/*
Kristian Rekstad
TDT4102 Prosedyre og objektorientert programmering
Vår 2016
Øving 4
*/

#include <iostream>
#include "tests.h"
#include "mastermind.h"

/*
1a:

int incrementByValueNumTimes(int, int, int);

int v0 = 5;
int increment = 2;
int iterations = 10;
int result = incrementByValueNumTimes(v0, increment, iterations);

v0 er 5, pga call by value.
*/

int main() {
	testPart1();
	testPart2();
	testPart3();
	
	std::cout << "Master mind" << std::endl;
	mastermind::playMasterMind();

	std::cin.ignore();
	std::cin.get();
}