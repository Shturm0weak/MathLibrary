#include <iostream>
#include "Matrix.h"

Matrix::Matrix(unsigned int n, unsigned int m) : n(n),m(m)
{
	m_matrix = new double*[n];

	for (unsigned int i = 0; i < n; i++) {
		m_matrix[i] = new double[m];
	}

	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < m; j++) {
			m_matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(unsigned int n, unsigned int m,double matrix[]) : n(n),m(m)
{
	m_matrix = new double*[n];

	for (unsigned int i = 0; i < n; i++) {
		m_matrix[i] = new double[m];
	}

	int counter = 0;
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < m; j++) {
			m_matrix[i][j] = matrix[counter];
			counter++;
		}
	}
}

double& Matrix::operator()(int i, int j)
{
	return (m_matrix[i][j]);
}

Matrix Matrix::operator*(double value)
{
	Matrix c(this->n, this->m);
	for (unsigned int i = 0; i < c.n; i++)
	{
		for (unsigned int j = 0; j < c.m; j++)
		{
			c(i, j) = this->operator()(i,j) * value;
		}
	}
	return c;
}

Matrix Matrix::operator*(Vector3D value)
{
	if (this->m == 3) {
		Matrix c(this->n, this->m);
		for (unsigned int i = 0; i < this->n; i++)
		{
			for (unsigned int j = 0; j < this->m; j++)
			{
				c(i, j) = this->operator()(i, j) * value[j];
			}
		}
		return c;
	}
}

Matrix Matrix::operator*(Matrix & b)
{
	if (this->n == b.m) {
		Matrix c(this->n,b.m);
		for (unsigned int i = 0; i < c.n; i++)
		{
			for (unsigned int j = 0; j < c.m; j++)
			{
				c(i,j) = 0;
				for (unsigned int k = 0; k < c.m - 1; k++)
					c(i, j) += this->operator()(i, k) * b.operator()(k,j);
			}
		}
		return c;
	}
}

void Matrix::Input()
{
	std::cout << "Input {" << this->n << "," << this->m << "}\n";
	for (unsigned int i = 0; i < this->n; i++)
	{
		for (unsigned int j = 0; j < this->m; j++)
		{
			std::cin >> this->operator()(i, j);
		}
	}
}

void Matrix::PrintMatrix(const Matrix & matrix)
{
	for (unsigned int i = 0; i < matrix.n; i++) {
		for (unsigned int j = 0; j < matrix.m; j++) {
			std::cout << (matrix.m_matrix[i][j]) << "	";
		}
		printf_s("\n");
	}
}