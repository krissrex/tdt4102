#include "Matrix.h"



Matrix::Matrix() : data(nullptr), rows(0), columns(0)
{
}


Matrix::Matrix(size_t nRows, size_t nColumns) : rows(nRows), columns(nColumns)
{
	// Array av pointers til doubles
	data = new double*[nColumns];
	
	// Lag alle radene, en av gangen
	for (size_t i = 0; i < nColumns; i++)
	{
		double *row = new double[nRows];
		// Sett cellene i hele raden til 0, så de ikke er udefinert
		for (size_t j = 0; j < nRows; j++)
		{
			row[j] = 0.0;
		}
		data[i] = row;
	}
}

Matrix::Matrix(size_t n) : Matrix(n, n)
{
	// Set to identity
	for (size_t i = 0; i < n; i++)
	{
		data[i][i] = 1.0;
	}
}

Matrix::~Matrix()
{
	std::cout << "Destroying matrix " << rows << "X" << columns << std::endl;

	if (isValid()) {
		for (size_t i = 0; i < columns; i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}
}

bool Matrix::isValid() const
{
	return data != nullptr;
}

size_t Matrix::getHeight() const
{
	return rows;
}

size_t Matrix::getWidth() const
{
	return columns;
}

double Matrix::get(unsigned int row, unsigned int col) const
{
	return data[col][row];
}

void Matrix::set(unsigned int row, unsigned int col, double value)
{
	data[col][row] = value;
}

std::ostream & operator<<(std::ostream & os, const Matrix & rhs)
{
	if (rhs.isValid()) {
		for (size_t i = 0; i < rhs.rows; i++)
		{
			for (size_t j = 0; j < rhs.columns; j++)
			{
				std::cout << rhs.data[j][i];

				// Ikke print \t på siste kolonne
				if (j != rhs.columns - 1) {
					std::cout << "\t";
				}
			}
			std::cout << std::endl;
		}
	}
	else {
		os << "Invalid matrix" << std::endl;
	}
	return os;
}
