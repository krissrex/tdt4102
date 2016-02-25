#pragma once
#include <iostream>

class Matrix2x2
{
public:
	Matrix2x2();
	// Params are named: row n column n:
	// row 1, column 0 = r1c0
	Matrix2x2(double r0c0, double r0c1, double r1c0, double r1c1);
	~Matrix2x2();

	double get(int row, int column) const;
	void set(int row, int column, double value);	void print() const;

	double det() const;
	// Returns true on success, false if det == 0
	bool inverse(Matrix2x2 &out) const;


	friend std::ostream& operator<<(std::ostream &stream, const Matrix2x2 &rhs);  // friend så den kan se numbers
	Matrix2x2& operator+=(const Matrix2x2 &rhs);
	Matrix2x2& operator-=(const Matrix2x2 &rhs);
	Matrix2x2& operator*=(const Matrix2x2 &rhs);

	Matrix2x2 operator+(const Matrix2x2 &rhs) const;
	Matrix2x2 operator-(const Matrix2x2 &rhs) const;
	Matrix2x2 operator*(const Matrix2x2 &rhs) const;

private:
	// [col][row], (0, 0) top left
	double numbers[2][2];
	
};

std::ostream& operator<<(std::ostream &os, const Matrix2x2 &rhs);

