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
	for (unsigned int i = 0; i < m; i++) {
		for (unsigned int j = 0; j < n; j++) {
			m_matrix[j][i] = matrix[counter];
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

Vector Matrix::operator*(Vector value)
{
	if (this->m == value.size) {
		Vector c(this->m);
		for (unsigned int j = 0; j < this->m; j++)
		{
			for (unsigned int i = 0; i < this->n; i++)
			{
				c.m_array[j] += this->operator()(i, j) * value.m_array[i];
				//printf_s("%lf = %lf * %lf\n", c.m_array[j], this->operator()(i, j), value[i]);
			}
			//std::cout << "\n";
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

double Matrix::Magnitude()
{
	double max = 0;
	for (int i = 0; i < n; i++) {
		double s = 0.0;
		for (int j = 0; j < m; j++) {
			s += abs(this->operator()(i,j));
		}
		if (s > max)
			max = s;
	}
	return max;
}

Matrix& Matrix::Transp()
{
	Matrix* mat = new Matrix(m,n);
	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; j < m; j++)
		{
			mat->operator()(j, i) = this->operator()(i, j);
		}
	}
	return *mat;
}

void Matrix::AssignCol(Vector vec, int col)
{
	if (vec.size != m) {
		return;
	}
	for (unsigned int i = 0; i < m; i++)
	{
		m_matrix[col][i] = vec[i];
	}
}

Vector Matrix::GetCol(int col)
{
	if (col < n) {
		Vector temp(m);
		for (unsigned int i = 0; i < m; i++)
		{
			temp[i] = this->m_matrix[col][i];
		}
		return temp;
	}
	return NULL;
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
	for (unsigned int i = 0; i < matrix.m; i++) {
		for (unsigned int j = 0; j < matrix.n; j++) {
			printf_s("%lf	", (matrix.m_matrix[j][i]));
		}
		printf_s("\n");
	}
}

void Matrix::PrintMatrix()
{
	for (unsigned int i = 0; i < m; i++) {
		for (unsigned int j = 0; j < n; j++) {
			printf_s("%lf	", (m_matrix[j][i]));
		}
		printf_s("\n");
	}
}
