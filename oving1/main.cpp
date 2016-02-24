/*
Kristian Rekstad
TDT4102 Prosedyre og objektorientert programmering
Vår 2016
Øving 1
*/

#include <iostream>
#include <vector>

using namespace std;

// 1
/*
Oversett til python:

bool isFibonacciNumber(int n){
	int a = 0;
	int b = 1;
	while (b < n){
		int temp = b;
		b = a + b;
		a = temp;
	}
	if (b == n){
		return true;
	}
	else{
		return false;
	}
}

Python:

def is_fibonacci_number(n):
	a = 0
	b = 1
	while b < n:
		temp = b
		b = a+b
		a = temp
	if b == n:
		return true
	else:
		return false
*/


// 2a
int fibonacci(int);
// 2b
void triangleNumbersBelow(int);
bool isTriangleNumber(int);
// 2c
int squareNumberSum(int);
// 2d
int max(int, int);
// 2e
bool isPrime(int);
// 2f
void naivePrimeNumberSearch(int n);
// 2g
int findGreatestDivisor(int n);
// 2h
void compareListOfNumbers(vector<int>);


int main() {
	fibonacci(20);
	
	triangleNumbersBelow(30);
	cout << "isTriangle - 21: " << (isTriangleNumber(21)?"yes":"no") << endl;;
	cout << "isTriangle - 25: " << (isTriangleNumber(25)?"yes":"no") << endl;
	
	cout << "Square number sums:" << endl;
	squareNumberSum(5);

	cout << "Max:" << endl;
	max(1, 0);
	max(-10, 100);
	max(30, 39);

	cout << "Prime: 3-" << (isPrime(3) ? "yes" : "no") << endl;
	cout << "Prime: 8-" << (isPrime(8) ? "yes" : "no") << endl;
	cout << "Prime: 19-" << (isPrime(19) ? "yes" : "no") << endl;

	cout << "Naive primes:" << endl;
	naivePrimeNumberSearch(50);

	cout << "Greatest divisor: 3-" << findGreatestDivisor(3) << endl;
	cout << "Greatest divisor: 16-" << findGreatestDivisor(16) << endl;
	cout << "Greatest divisor: 27-" << findGreatestDivisor(27) << endl;
	cout << "Greatest divisor: 29-" << findGreatestDivisor(29) << endl;

	vector<int> list{ -1, 0, -10, 2, 0, 5, 10, 11, -2 };
	cout << "Comparing [";
	for (size_t i = 0; i < list.size()-1; i++)
	{
		cout << list[i] << ",";
	}
	cout << list[list.size() - 1];
	cout << "]:" << endl;
	compareListOfNumbers(list);

	// Vinduet lukkes selv med subsystem satt til console :(
	cin.get();
	return 0;
}

///////////

int fibonacci(int n) {
	/*
	def fibonacci(n):
		a = 0
		b = 1
		print ("Fibonacci numbers:")
		for x in range(1,n):
			temp = b
			b = a + b
			a = temp
			print (x,b)
		print("----")
		return b
	*/

	int a = 0;
	int b = 1;
	cout << "Fibonacci numbers:" << endl;
	for (int x = 1; x < n; x++) {
		int temp = b;
		b = a + b;
		a = temp;
		cout << x << " " << b << endl;
	}
	cout << "----" << endl;
	return b;
}

///////////

void triangleNumbersBelow(int n) {
	/*
	def triangleNumbersBelow(n) :
		acc = 1
		num = 2
		print("Triangle numbers below ", n, ":")
		while acc + num < n :
			acc = acc + num
			num = num + 1
			print(acc)
		print()
	*/
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":" << endl;
	while (acc + num < n) {
		acc += num;
		num++;
		cout << acc << endl;
	}
	cout << endl;
}

bool isTriangleNumber(int number) {
	/*
	def isTriangleNumber(number) :
		acc = 1
		while (number > 0) :
			number = number - acc
			acc = acc + 1
		if number == 0 :
			return True
		else :
			return False
	*/
	int acc = 1;
	while (number > 0) {
		number -= acc;
		acc++;
	}
	return number == 0;
}

///////////

int squareNumberSum(int n) {
	/*
	def squareNumberSum(n) :
		totalSum = 0
		for i in range(n) :
			totalSum += i*i
			print(i*i)
		print(totalSum)
		return (totalSum)
	*/

	int totalSum = 0;
	for (int i = 0; i < n; i++)
	{
		totalSum += i*i;
		cout << i*i << endl;
	}
	cout << totalSum << endl;
	return totalSum;
}

///////////

int max(int a, int b) {
	/*
	def max(a, b) :
		if a > b:
			print("A is greater than B")
			return a
		else :
			print("B is greater than or equal A")
			return b
	*/

	if (a > b){
		cout << "A is greater than B" << endl;
		return a;
	}
	else {
		cout << "B is greater than or equal A" << endl;
		return b;
	}
}

///////////

bool isPrime(int n) {
	/*
	def isPrime(n):
		primeness = True
		for j in range(2, n) :
			if n%j == 0 :
				primeness = False
				break
		return primeness
	*/

	bool primeness = true;
	for (int j = 2; j < n; j++) {
		if (n%j == 0) {
			primeness = false;
			break;
		}
	}
	return primeness;
}

///////////

void naivePrimeNumberSearch(int n) {
	/*
	def naivePrimeNumberSearch(n):
		for number in range(2,n):
			if isPrime(number):
				print (number, " is a prime")

	*/

	for (int number = 2; number < n; number++)
	{
		if (isPrime(number)) {
			cout << number << " is a prime" << endl;
		}
	}
}

///////////

int findGreatestDivisor(int n) {
	/*
	def findGreatestDivisor(n):
		for divisor in range(n-1,0,-1):
			if n%divisor == 0:
				return divisor
	*/

	for (int divisor = n-1; divisor > 0; divisor--)
	{
		if (n%divisor == 0) {
			return divisor;
		}
	}
	return -1;
}

///////////

void compareListOfNumbers(vector<int> l) {
	/*
	def compareListOfNumbers(l):
	r = [0]*3
	for i in l:
		if i < 0:
			r[0] += 1
		elif i == 0:
			r[1] += 1
		else:
			r[2] += 1
	print (r[0]," numbers were below zero")
	print (r[1], " number were zero")
	print (r[2], " numbers were greater than zero")
	*/

	int r[] = { 0, 0, 0 };
	for each (int i in l) {
		if (i < 0) {
			r[0]++;
		}
		else if (i == 0) {
			r[1]++;
		}
		else {
			r[2]++;
		}
	}

	cout << r[0] << " numbers were below zero" << endl;
	cout << r[1] << " numbers were zero" << endl;
	cout << r[2] << " numbers were greater than zero" << endl;
}