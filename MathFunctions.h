#pragma once
#include "MathLibrary.h"

namespace math {

	MATH_API double Magnitude(Matrix& matrix); 
	MATH_API void Print(const Matrix& matrix);
	MATH_API void Print(const Vector& vec);
	MATH_API void Input(Matrix& matrix); 
	MATH_API Matrix Transpose(const Matrix& matrix);
	MATH_API Matrix Cofactor(const Matrix& matrix, int p, int q);
	MATH_API int Determinant(const Matrix& matrix,int n);
	MATH_API Matrix Adjoint(const Matrix& matrix);
	MATH_API Matrix Inverse(const Matrix& matrix);
	MATH_API Vector Normalize(const Vector& vec);
}