/*
Kristian Rekstad
TDT4102 Prosedyre og objektorientert programmering
Vår 2016
Øving 7
*/

#include <iostream>
#include "Matrix.h"

using namespace std;

// 1a
void fillInFibonacciNumbers(int[], int);
// 1b
void printArray(int[], int);
// 1c
void createFibonacci();

// 3g - test av slettet copy-constructor
Matrix test(Matrix asdf);

int main() {
	createFibonacci();

	// 2g
	cout << "Matrix test" << endl << endl;

	Matrix a = Matrix(2);
	Matrix b(4);
	Matrix c(3, 5);

	b.set(0, 2, 4.0);

	cout << "A:" << endl << a;
	cout << "B:" << endl << b;
	cout << "C:" << endl << c;

	// 3
	cout << endl << "Kopieringstest" << endl << endl;
	
	cout << "A:" << endl << a << "B:" << b << endl;
	a = b;
	cout << "A = B" << endl << "A:" << endl << a << "B:" << b << endl;
	b.set(1, 3, 7.0);
	cout << "A:" << endl << a << "B:" << b << endl;

	// Det er operator= som brukes
	// A endres også. Den har samme peker i data som B.
	// Data kopieres ikke med "deep copy", kun kopi av peker-verdi
	
	// 3b
	Matrix C(a);
	// Den kjører den standard copy-constructoren Matrix(Matrix &original).

	// 3c
	Matrix d = b;
	// Den kjører den standard copy-constructoren Matrix(Matrix &original).

	// 3f: 3c er litt uforventet

	// 3g
	//Matrix asd = test(b);
	// Gir feil på både test og b.

	cin.ignore();
	cin.get();
}

void fillInFibonacciNumbers(int result[], int length) {
	int current = 0;
	int next = 1;
	int temp = 0;

	for (size_t i = 0; i < length; i++)
	{
		result[i] = current;
		temp = current;
		current = next;
		next += temp;
	}
}

void printArray(int arr[], int length) {
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void createFibonacci() {
	// 1. Spør brukeren hvor mange tall som skal genereres
	int num;
	cout << "Hvor mange fibonacci tall?" << endl;
	cin >> num;

	// 2. Alloker minne til en tabell som er stor nok til tallrekka
	int *fibs = new int[num];
	
	// 3. Fylle tabellen med funksjonen fillInFibonacciNumbers
	fillInFibonacciNumbers(fibs, num); // overflower ved num > 47

	// 4. Skriv ut resultatet til skjerm med printArray
	printArray(fibs, num);		// 5. Frigjør minnet du har reservert	delete[] fibs;
}

Matrix test(Matrix asdf)
{
	// Gir feil på asdf
	return asdf;
}
