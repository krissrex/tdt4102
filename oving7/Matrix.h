#pragma once

#include <iostream>

class Matrix
{
public:
	// Creates an invalid matrix
	Matrix();
	// Creates an nRows x nColumns zero matrix
	Matrix(size_t nRows, size_t nColumns);
	// Creates an N x N square identity matrix
	explicit Matrix(size_t n);

	~Matrix();

	// 3d
	//Matrix &operator=(Matrix rhs) = delete;
	// 3e
	//Matrix(Matrix &original) = delete;

	bool isValid() const;
	size_t getHeight() const;
	size_t getWidth() const;
	// Get the value at (row, col). Don't call this if isValid() returns false
	double get(unsigned int row, unsigned int col) const;
	void set(unsigned int row, unsigned int col, double value);

	friend std::ostream& operator<<(std::ostream& os, const Matrix &rhs);

private:
	double **data;
	size_t rows;
	size_t columns;
};

std::ostream& operator<<(std::ostream& os, const Matrix &rhs);
