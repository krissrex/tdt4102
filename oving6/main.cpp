/*
Kristian Rekstad
TDT4102 Prosedyre og objektorientert programmering
Vår 2016
Øving 6
*/

#include "Matrix2x2.h"
#include "Vector2.h"
#include <iostream>

#define oppg2e false

using namespace std;

// 4c
Vector2 operator*(const Matrix2x2 &lhs, const Vector2 &rhs) {
	// Kvifor gir det inga meining å implementere operatoren *= i dette tilfellet?
	//		Fordi vec *= matr
	//		er vec = vec * matr
	//		men egentlig skal det være vec = matr * vec.

	double topRow = lhs.get(0, 0)*rhs.get(0) + lhs.get(0, 1)*rhs.get(1);
	double bottomRow = lhs.get(1, 0)*rhs.get(0) + lhs.get(1, 1)*rhs.get(1);
	
	return Vector2(topRow, bottomRow);
}

void solve2eqs();

int main() {
	Matrix2x2 matr;
	matr.print();

	cout << matr.get(0, 1) << endl;
	matr.set(0, 1, 3.9);
	cout << matr.get(0, 1) << endl;
	matr.print();

	Matrix2x2 matrWithConstructor(3.14, 1.59, 2.65, 3.58);
	matrWithConstructor.print();

	Matrix2x2 a(1, 2, 3, 4);
	Matrix2x2 b(4, 3, 2, 1);
	Matrix2x2 c(1.0, 3.0, 1.5, 2.0);

	cout << endl << "Operator overload tests" << endl;

	a += b;
	a.print();
	cout << endl;
	a -= b;
	a.print();

	cout << endl << "Multiplication" << endl;

	if (oppg2e) {
		// 2e
		Matrix2x2 d = a + b;
		cout << d << endl;
		d = d*b - a + c;
		cout << d;
	}
	else {
		// 2g
		Matrix2x2 d = a + b;
		cout << d << endl;
		d *= b;
		d -= a;
		d += c;
		cout << d;
	}

	Vector2 vec(2, 5);
	cout << a*vec << endl;

	// 5
	solve2eqs();

	cin.ignore();
	cin.get();
}


void solve2eqs() {
	cout << "I : ax + by = p" << endl 
		 << "II : cx + dy = q" << endl << endl;

	double ins[6]{ 0 };

	for (size_t i = 0; i < 6; i++)
	{
		char offset = 'a';
		if (i >= 4) {
			offset = 'p'-4;
		}
		cout << "Enter " << char(offset + i) << ": " << endl;
		cin >> ins[i];
	}
	
	Matrix2x2 a(ins[0], ins[1], ins[2], ins[3]);

	Vector2 vec(ins[4], ins[5]);

	Matrix2x2 invA;
	if (a.inverse(invA)) {
		Vector2 xy = invA * vec;
		cout << "Solution: " << endl << xy << endl;
	}
	else {
		cout << "No solution for " << endl << a << "and" << endl << vec << endl;
	}

}