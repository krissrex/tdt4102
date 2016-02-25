#include "Vector2.h"
#include <cmath>


Vector2::Vector2() : numbers{ 0, 0 }
{
}


Vector2::Vector2(double r1, double r2) : numbers{ r1, r2 }
{
}

Vector2::~Vector2()
{
}

void Vector2::set(int row, double value)
{
	numbers[row] = value;
}

double Vector2::get(int row) const
{
	return numbers[row];
}

double Vector2::dot(const Vector2 & rhs) const
{
	/*
	Kva betyr const som står bak disse funksjonshovuda?
		const indikerer at medlemsfunksjonen ikke skal endre på objektet del kalles på		Når bør ein nytte const på denne måten?		for alt av medlemsfunksjoner som ikke skal endre objektet, som get*().
	*/

	return numbers[0]*rhs.numbers[0] + numbers[1]*rhs.numbers[1];
}

double Vector2::lengthSquared() const
{
	return dot(*this);
}

double Vector2::length() const
{
	return sqrt(lengthSquared());
}

std::ostream & operator<<(std::ostream & os, const Vector2 & rhs)
{
	os << "|" << rhs.numbers[0] << std::endl << "|" << rhs.numbers[1] << std::endl;
	return os;
}
