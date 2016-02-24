/*
Kristian Rekstad
TDT4102 Prosedyre og objektorientert programmering
Vår 2016
Øving 3
*/
#include "cannonball.h"
#include "input.h"
#include "utilities.h"
#include <cmath>
#include <iostream>
#include <ctime>

bool is(double num, double correct) {
	double deviation = std::pow(correct - num, 2.0);
	if (deviation < 0.001) {
		std::cout << "Riktig svar: " << num << std::endl;
		return true;
	}
	else {
		std::cout << "Feil svar: " << num << ", skulle vært: " << correct << std::endl;
		return false;
	}
}

int main() {
	/*
	Test-data
			T = 0	T = 2.5		T = 5.0
	acclX	0		0 0			0.0
	acclY	-9.81	-9.81		-9.81
	velX	50.0	50.0		50.0
	velY	25.0	0.475		-24.05
	posX	0.0		125.0		250.0
	posY	0.0		31.84		2.375
	*/
	
	is(cb::acclY(), -9.81);
	is(cb::velY(25, 2.5), 0.475);
	is(cb::velY(25, 5.0), -24.05);
	is(cb::posX(50, 2.5), 125);
	is(cb::posX(50, 5.0), 250);
	is(cb::posY(25, 2.5), 31.84);
	is(cb::posY(25, 5.0), 2.375);
	std::cout << "Flight time " << cb::flightTime(25) << std::endl;
	cb::printTime(5);
	

	std::cout << "Distance traveled (50,25): " << cb::getDistanceTraveled(50, 25) << std::endl;
	double theta, absVelocity;
	input::getUserInput(&theta, &absVelocity);
	double velX, velY;
	input::getVelocityVector(theta, absVelocity, &velX, &velY);
	std::cout << "Velocity: " << velX << ", " << velY << std::endl;

	std::srand(std::time(NULL));
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Random tall: " << random::randomWithLimits(10, 100) << std::endl;
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Bedre random tall: " << random::modernRandomWithLimits(10, 100) << std::endl;
	}

	std::cout << std::endl;
	cb::playTargetPractice();

	std::cin.ignore();
	std::cin.get();
	return 0;
}