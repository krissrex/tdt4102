#pragma once

/*cannonball*/
namespace cb {

	double acclY();
	double velY(double initVelocityY, double time);
	double posX(double initVelocity, double time);
	double posY(double initVelocity, double time);
	void printTime(double time);
	double flightTime(double initVelocityY);

	double getDistanceTraveled(double velocityX, double velocityY);
	double targetPractice(double distanceToTarget, double velocityX, double velocityY);
	void playTargetPractice();
}