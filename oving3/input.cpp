#include "input.h"
#include <iostream>
#include <cmath>

void input::getUserInput(double * theta, double * absVelocity)
{
	std::cout << "Theta: ";
	std::cin >> *theta;
	std::cout << "Absolute velocity: ";
	std::cin >> *absVelocity;
}

double input::getVelocityX(double theta, double absVelocity)
{
	return absVelocity*std::cos(theta);
}

double input::getVelocityY(double theta, double absVelocity)
{
	return absVelocity*std::sin(theta);
}

void input::getVelocityVector(double theta, double absVelocity, double * velocityX, double * velocityY)
{
	*velocityX = getVelocityX(theta, absVelocity);
	*velocityY = getVelocityY(theta, absVelocity);
}
