#pragma once
#include <iostream>

class Vector2
{
public:
	Vector2();
	// r1 is row 1, r2 is row 2
	Vector2(double r1, double r2);
	~Vector2();

	void set(int row, double value);
	double get(int row) const;

	double dot(const Vector2 &rhs) const;
	double lengthSquared() const;
	double length() const;

	friend std::ostream& operator<<(std::ostream &os, const Vector2 &rhs);

private:
	double numbers[2];
};

std::ostream& operator<<(std::ostream &os, const Vector2 &rhs);