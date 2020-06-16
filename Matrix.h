#pragma once
#include "Vector.h"

class Matrix {

public:
	unsigned int n = 1;
	unsigned int m = 1;
	double** m_matrix = nullptr;
	Matrix(unsigned int n, unsigned int m);
	Matrix(unsigned int n, unsigned int m,double matrix[]);

	double& operator()(int i, int j);

	Matrix operator*(double value);
	Vector operator*(Vector value);
	Matrix operator*(Matrix& b);
	double Magnitude();
	Matrix& Transp();

	void AssignCol(Vector vec, int col);
	Vector GetCol(int col);

	void Input();

	static void PrintMatrix(const Matrix& matrix);
	void PrintMatrix();

};

