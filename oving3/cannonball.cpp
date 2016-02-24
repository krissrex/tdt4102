#include "cannonball.h"
#include "input.h"
#include "utilities.h"
#include <iostream>
#include <cmath>

namespace cb {
	double yAccel = -9.81;

double acclY()
{
	return yAccel;
}
}


double cb::velY(double initVelocityY, double time)
{
	return initVelocityY + time*yAccel;
}

double cb::posX(double initVelocity, double time)
{
	return initVelocity*time; // acclX()*time*time / 2.0;
}

double cb::posY(double initVelocity, double time)
{
	return initVelocity*time + acclY()*time*time / 2.0;
}

void cb::printTime(double time)
{
	
	double sec = std::fmod(time, 60);
	time -= sec;
	int minutes = (int)fmod(time / 60.0, 60);
	time -= 60.0 * minutes;
	int hours = (int)(time / (60.0 * 60.0));

	std::cout << hours << ":" << minutes << ":" << sec << std::endl;
	
}

double cb::flightTime(double initVelocityY)
{
	return -2.0*initVelocityY/acclY();
}

double cb::getDistanceTraveled(double velocityX, double velocityY)
{
	double time = flightTime(velocityY);
	return posX(velocityX, time);
}

double cb::targetPractice(double distanceToTarget, double velocityX, double velocityY)
{
	return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

void cb::playTargetPractice()
{
	// Target
	double pos = random::modernRandomWithLimits(100, 1000);
	std::cout << "Blink er på " << pos << std::endl;

	bool hit = false;

	for (int i = 0; i < 10; i++)
	{
		// User input
		double theta, absVelocity;
		input::getUserInput(&theta, &absVelocity);
		double velX, velY;
		input::getVelocityVector(theta, absVelocity, &velX, &velY);

		// Distance check
		double dist = targetPractice(pos, velX, velY);
		std::cout << "Du var " << dist << " unna blinken" << std::endl;
		
		if (dist < 5.0) {
			hit = true;
			break;
		}

		std::cout << "Du skøyt for " << (dist > pos ? "langt" : "kort") << std::endl;
	}

	if (hit) {
		std::cout << "Gratulerer, du vant!" << std::endl;
	}
	else {
		std::cout << "Du tapte" << std::endl;
	}

}
