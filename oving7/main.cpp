/*
Kristian Rekstad
TDT4102 Prosedyre og objektorientert programmering
Vår 2016
Øving 7
*/

#include <iostream>
#include "Matrix.h"
#include <memory>

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

	Matrix a;
	Matrix b(4);
	Matrix c(3, 5);

	b.set(0, 2, 4.0);

	cout << "A:" << endl << a;
	cout << "B:" << endl << b;
	cout << "C:" << endl << c;

	// 3
	cout << endl << "Kopieringstest" << endl << endl;
	
	cout << "A:" << endl << a << "B:" << endl << b << endl;
	a = b;
	cout << "A = B" << endl << "A:" << endl << a << "B:" << endl << b << endl;
	b.set(1, 3, 7.0);
	cout << "A:" << endl << a << "B:" << endl << b << endl;

	// Det er operator= som brukes
	// A endres også. Den har samme peker i data som B.
	// Data kopieres ikke med "deep copy", kun kopi av peker-verdi
	
	// 3b
	Matrix _c(a);
	// Den kjører den standard copy-constructoren Matrix(Matrix &original).

	// 3c
	Matrix d = b;
	// Den kjører den standard copy-constructoren Matrix(Matrix &original).

	// 3f: 3c er litt uforventet

	// 3g
	//Matrix asd = test(b);
	// Gir feil på både test og b.

	// 5a
	Matrix lhs(3);
	Matrix rhs(3);
	rhs.set(1, 1, 5);
	lhs += rhs;
	cout << "Valid +=" << endl << lhs << endl;
	rhs = Matrix(5);
	cout << "Invalid +=" << endl << lhs << endl;

	// 5c
	Matrix A(2), B(2), C(2);
	A.set(0, 1, 2); A.set(1, 0, 3); A.set(1, 1, 4);
	B.set(0, 0, 4); B.set(0, 1, 3); B.set(1, 0, 2);
	C.set(0, 1, 3); C.set(1, 0, 1.5); C.set(1, 1, 2);

	A += B + C;
	cout << "A += B + C" << endl << A;
	/*
	Skal bli
	6    8
	6.5  7

	som den også gir når kjørt :)
	*/
	
	// Litt rart at øvingen har smart pointers som mål, men ikke ber oss bruke det
	unique_ptr<int> test = make_unique<int>(4);  // unique, sletter data i destructor
	shared_ptr<int> test2 = make_shared<int>(6);  // shared, refcounted
	shared_ptr<int> test2_2{ test2 };  // deler data med test2. Når begge går ut av scope slettes 6

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
