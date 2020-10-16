#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "MathFunctions.h"

using namespace math;

Vector math::Normalize(Vector& vec)
{
	return (Vector(vec * (1 / vec.Length())));
}

double math::Magnitude(Matrix& matrix)
{
	double max = 0;
	for (uint32_t i = 0; i < matrix.m; i++) {
		double s = 0.0;
		for (uint32_t j = 0; j < matrix.n; j++) {
			s += abs(matrix.operator()(i, j));
		}
		if (s > max)
			max = s;
	}
	return max;
}

Matrix math::Transpose(Matrix& matrix)
{
	Matrix mat(matrix.m, matrix.n);
	for (uint32_t i = 0; i < matrix.m; i++)
	{
		for (uint32_t j = 0; j < matrix.n; j++)
		{
			mat.operator()(j, i) = matrix.operator()(i, j);
		}
	}
	return mat;
}

void math::Input(Matrix & matrix)
{
	std::cout << "Input {" << matrix.m << "," << matrix.n << "}\n";
	for (uint32_t i = 0; i < matrix.m; i++)
	{
		for (uint32_t j = 0; j < matrix.n; j++)
		{
			std::cin >> matrix.operator()(i, j);
		}
	}
}

void math::Print(const Matrix & matrix)
{
	for (uint32_t i = 0; i < matrix.m; i++) {
		for (uint32_t j = 0; j < matrix.n; j++) {
			printf_s("%lf	", (matrix.m_matrix[i * matrix.m + j]));
		}
		printf_s("\n");
	}
}

void math::Print(const Vector & vec)
{
	for (uint32_t i = 0; i < vec.m_size; i++)
	{
		printf_s("%.12lf\n", vec.m_array[i]);
	}
}
