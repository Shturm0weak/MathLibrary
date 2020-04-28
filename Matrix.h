#pragma once
#include "Vector3D.h"
class Row;

class Matrix {
	double** m_matrix = nullptr;
	unsigned int n = 1;
	unsigned int m = 1;
public:

	Matrix(unsigned int n, unsigned int m);
	Matrix(unsigned int n, unsigned int m,double matrix[]);

	double& operator()(int i, int j);

	Matrix operator*(double value);
	Matrix operator*(Vector3D value);
	Matrix operator*(Matrix& b);

	void Input();

	static void PrintMatrix(const Matrix& matrix);

};

