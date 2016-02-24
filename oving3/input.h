#pragma once

namespace input {
	// Ber brukeren om to tall, en vinkel, og en fart.
	// Disse verdiene skal lagres i minnet som pekerne
	// theta og absVelocity peker paa.
	void getUserInput(double *theta, double *absVelocity);
	// Returnerer henholdsvis farten i X-, og Y-retning, gitt en vinkel
	// theta og en absoluttfart absVelocity.
	double getVelocityX(double theta, double absVelocity);
	double getVelocityY(double theta, double absVelocity);
	// Dekomponerer farten gitt av absVelocity, i X- og Y-komponentene
	// gitt vinkelen theta. Disse komponentene lagres i minnet.
	void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY);
}