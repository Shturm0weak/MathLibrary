#pragma once
#include "MathLibrary.h"

namespace math {

	MATH_API double Magnitude(Matrix& matrix);
	MATH_API bool IsCloseEnough(double a, double b);
	MATH_API void Print(const Matrix& matrix);
	MATH_API void Print(const Vector& vector);
	MATH_API void Input(Matrix& matrix);
	MATH_API Matrix Transpose(const Matrix& matrix);
	MATH_API Matrix Cofactor(const Matrix& matrix, int64_t p, int64_t q);
	MATH_API int64_t Determinant(const Matrix& matrix, int64_t n);
	MATH_API Matrix Adjoint(const Matrix& matrix);
	MATH_API Matrix Inverse(const Matrix& matrix);
	MATH_API Vector GaussianElimination(const Matrix& matrix, const Vector& vector);
	MATH_API int64_t ForwardElimination(Matrix& matrix);
	MATH_API Vector BackSubstitutian(Matrix& matrix);
	MATH_API Vector  Normalize(const Vector& vector);
}