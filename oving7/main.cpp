/*
Kristian Rekstad
TDT4102 Prosedyre og objektorientert programmering
Vår 2016
Øving 7
*/

#include <iostream>


using namespace std;

// 1a
void fillInFibonacciNumbers(int[], int);
// 1b
void printArray(int[], int);
// 1c
void createFibonacci();

int main() {
	createFibonacci();

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