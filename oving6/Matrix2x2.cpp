#include "Matrix2x2.h"
#include <iostream>


Matrix2x2::Matrix2x2() : numbers{ { 1, 0 },{ 0, 1 } }
{
}


Matrix2x2::Matrix2x2(double r0c0, double r0c1, double r1c0, double r1c1) : numbers{ {r0c0, r1c0}, {r0c1, r1c1} }
{
}

Matrix2x2::~Matrix2x2()
{
}

double Matrix2x2::get(int row, int column) const
{
	return numbers[column][row];
}

void Matrix2x2::set(int row, int column, double value)
{
	numbers[column][row] = value;
}

void Matrix2x2::print() const
{
	// Før jeg overloaded <<, brukte jeg det som står i overload-implementasjonen med std::cout. 
	std::cout << *this;
}

double Matrix2x2::det() const
{
	return numbers[0][0]*numbers[1][1] - numbers[0][1]*numbers[1][0];
}

bool Matrix2x2::inverse(Matrix2x2 & out) const
{
	double d = det();
	if (d == 0) {
		return false;
	}

	d = 1.0 / d;

	out.numbers[0][0] = numbers[1][1] * d;
	out.numbers[0][1] = -numbers[0][1] * d;
	out.numbers[1][0] = -numbers[1][0] * d;
	out.numbers[1][1] = numbers[0][0] * d;

	return true;
}


Matrix2x2& Matrix2x2::operator+=(const Matrix2x2 & rhs)
{
	/*
	Kvifor kan vi ikkje berre skrive: this = *this + rhs;
		Fordi vi ikke har overloaded operator+, så vi må addere numbers.

	Kvifor kan du nytte operatorane += og -= når du arbeider med elementa i matrisa?
		Fordi double har en operator+= 
	*/
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			numbers[i][j] += rhs.numbers[i][j];
		}
	}
	return *this;
}

Matrix2x2 & Matrix2x2::operator-=(const Matrix2x2 & rhs)
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			numbers[i][j] -= rhs.numbers[i][j];
		}
	}
	return *this;
}

Matrix2x2 & Matrix2x2::operator*=(const Matrix2x2 & rhs)
{
	/*
	Kvifor kan du ikkje implementere *= på same måte som vi implementerte += og -= tidlegare?
		Kan ikke lengre bruke *= på hvert element i arrayet, fordi det ikke er vanlig multiplikasjon

	Kan du implementere *= ved å gjenbruke kode du har skrive allereie?
		Ja, slik:
	*/

	Matrix2x2 temp = *this * rhs;
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			numbers[i][j] = temp.numbers[i][j];
		}
	}

	return *this;
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2 & rhs) const
{
	// Bruker den implisitte copy-constructoren
	Matrix2x2 result(*this);
	result += rhs;

	return result;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2 & rhs) const
{
	Matrix2x2 result = Matrix2x2(*this);
	result -= rhs;

	return result;
}

Matrix2x2 Matrix2x2::operator*(const Matrix2x2 & rhs) const
{
	Matrix2x2 result(0, 0, 0, 0);

	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			for (size_t k = 0; k < 2; k++)
			{
				result.numbers[j][i] += numbers[k][i] * rhs.numbers[k][j];
			}
		}
	}
	return result;
}

std::ostream & operator<<(std::ostream & os, const Matrix2x2 & rhs)
{
	/*
	Kvifor bør denne funksjonen ta const argument? (t.d. const Matrix2x2 &rhs)
		For vi vil ikke endre rhs når vi printer den

	Når bør vi, og når bør vi ikkje (evt kan ikkje) nytte const-argument?
		Bør ikke være const hvis vi skal endre på data i argumentet
	*/

	os << "|" << rhs.numbers[0][0] << " | " << rhs.numbers[1][0] << std::endl 
	   << "|" << rhs.numbers[0][1] << " | " << rhs.numbers[1][1] << std::endl;

	return os;
}
