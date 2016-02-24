/*
Kristian Rekstad
TDT4102 Prosedyre og objektorientert programmering
Vår 2016
Øving 2
*/

#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>

using namespace std;

// 1a
void inputAndPrintInteger();
// 1b
int inputInteger();
// 1c
void inputIntegersAndPrintSum();
// 1e
bool isOdd(int);
// 1f
void printHumanReadableTime(int);

// 2a
void inputIntegersUsingLoopAndPrintSum();
// 2c
double inputDouble();
// 2d
void convertNokToEuro();

// 3a
int meny();
static array<char*, 7> valg = { "Avslutt", "Summer to tall", "Summer flere tall",
		"Konverter NOK til EUR", "Lag gangetabell", "Løs andregradslikning", "Beregn avdrag" };
// 3b
void multiplicationMatrix();

// 4a
float discriminant(float, float, float);
// 4b
void printRealRoots(float, float, float);
// 4c
void solveQuadraticEquation();

// 5a
void calculateLoanPayments(float, float);

int main() {
	/*
	cout << "1a" << endl;
	inputAndPrintInteger();
	
	cout << "1b" << endl;
	cout << "Du skrev: " << inputInteger() << endl;

	cout << "1c" << endl;
	inputIntegersAndPrintSum();

	cout << "1e" << endl;
	for (int i = 10; i < 15; i++) {
		if (isOdd(i)) {
			std::cout << i << " er et oddetall." << std::endl;
		}
		else {
			std::cout << i << " er et partall." << std::endl;
		}
	}

	cout << "1f" << endl;
	printHumanReadableTime(10000);
	
	cout << "2a" << endl;
	inputIntegersUsingLoopAndPrintSum();

	cout << "2d" << endl;
	convertNokToEuro();
	*/

	cout << "Meny-system" << endl << endl;

	int valg = meny();
	while (valg != 0)
	{
		switch (valg)
		{
		case 1: inputIntegersAndPrintSum(); break;
		case 2: inputIntegersUsingLoopAndPrintSum(); break;
		case 3: convertNokToEuro(); break;
		case 4: multiplicationMatrix(); break;
		case 5: solveQuadraticEquation(); break;
		case 6: calculateLoanPayments(10000, 3.4); break;
		default: break;
		}
		valg = meny();
	}

	return 0;
}


void inputAndPrintInteger() {
	cout << "Skriv heltall: ";
	int x;
	cin >> x;
	cout << "Du skrev: " << x << endl;
}

int inputInteger() {
	cout << "Skriv heltall: ";
	int x;
	cin >> x;
	return x;
}

void inputIntegersAndPrintSum() {
	// 1d: brukte inputInteger fordi jeg trenger tallet brukeren skrev
	int x = inputInteger();
	int y = inputInteger();
	cout << "Summen av tallene: " << x + y << endl;
}

bool isOdd(int x) {
	return x % 2;
}

void printHumanReadableTime(int seconds)
{
	int temp = seconds;
	int sec = temp % 60;
	temp -= sec;
	int minutes = (temp / 60) % 60;
	temp -= 60 * minutes;
	int hours = (temp / (60*60));

	cout << seconds << " sekunder er " << hours << " timer, " << minutes << " minutter og " << sec << " sekunder." << endl;
}

void inputIntegersUsingLoopAndPrintSum()
{
	cout << "Hvor mange tall (-1 = uendelig): ";
	int num;
	cin >> num;

	int sum = 0;

	// 2b: hvis man vet antall på forhånd, er for-loop best

	if (num == -1) {
		while (true)
		{
			int x = inputInteger();
			if (x == 0) break;
			sum += x;
		}
	}
	else {
		for (size_t i = 0; i < num; i++)
		{
			int x = inputInteger();
			sum += x;
		}
	}
	
	cout << "Summen er: " << sum << endl;
}

double inputDouble()
{
	cout << "Skriv et desimaltall: ";
	double x; 
	cin >> x;
	return x;
}

void convertNokToEuro()
{
	cout << "Oppgi antall nok som skal konverteres:" << endl << "\t";
	double x = inputDouble();

	while (x < 0)
	{
		cout << "Tallet var negativt. Venligst prøv igjen:" << endl << "\t";
		x = inputDouble();
	}

	double nok2eur = 9.64;
	cout << setprecision(2) << fixed << x << " nok er " << x/nok2eur << " euro." << endl;

	// 2e: bruker inputDouble så man kan skrive nok med øre. passer på at x er double, for å ikke få trunkering av desimaler
	//     retur-type void fordi oppgaven ber oss bare om å printe, ikke returnere noe
}

int meny()
{
	cout << "Velg funksjon:" << endl;

	for (size_t i = 0; i < valg.size(); i++)
	{
		cout << i << ") " << valg[i] << endl;
	}
	cout << "Angi valg (0-" << valg.size()-1 << "): ";
	int x;
	cin >> x;

	return x;
}

void multiplicationMatrix()
{
	cout << "Gangetabell" << endl;
	int w, h;
	cout << "Skriv bredde: ";
	cin >> w;
	cout << "Skriv høyde: ";
	cin >> h;

	cout << "\t";
	for (size_t i = 1; i <= w; i++)
	{
		cout << i << "\t";
	}
	cout << endl;

	for (size_t i = 1; i <= h; i++)
	{
		cout << i << ": \t";
		for (size_t j = 1; j <= w; j++)
		{
			cout << i*j << "\t";
		}
		cout << endl;
	}

}

float discriminant(float a, float b, float c)
{
	return b*b - 4.0 * a*c;
}

void printRealRoots(float a, float  b, float c)
{
	float disc = discriminant(a, b, c);
	if (disc < 0) {
		cout << "Ingen røtter" << endl;
		return;
	}

	float extrema = -b / 2.0*a;
	if (disc == 0) {
		cout << "1 rot: " << extrema << endl;
	}
	else {
		float offset = sqrtf(disc) / (2.0*a);
		cout << "Rot 1: " << extrema + offset << endl;
		cout << "Rot 2: " << extrema - offset << endl;
	}


}

void solveQuadraticEquation()
{
	float a, b, c;
	cout << "Løs andregradslikning" << endl << "Oppgi a, b og c:" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "Røtter for " << a << "x^2 + " << b << "x + " << c << endl;

	printRealRoots(a, b, c);
}

void calculateLoanPayments(float belop, float rente)
{
	int numAvdrag = 10;

	cout << "Lån med beløp " << belop << ", rente " << rente << " og " << numAvdrag << " avdrag" << endl;

	float temp = belop;
	int year = 1;

	cout << "År \tInnbetaling \tGjennstående lån" << endl;
	while (temp > 0)
	{
		float innbetaling = (belop / numAvdrag) + (rente / 100.0)*temp;
		temp -= innbetaling;
		temp = max(0.f, temp);
		cout << year << "\t" << innbetaling << "    \t" << temp << endl;

		year++;
	}
}


