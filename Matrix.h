#ifndef MATRIX_H_
#define MATRIX_H_
#include <mutex>
#include "MathLibrary.h"

namespace math {

	class Vector;

	class MATH_API Matrix {
	public:

		double* m_matrix = nullptr;
		uint32_t m_Rows = 1;
		uint32_t m_Cols = 1;
		Matrix(uint32_t rows, uint32_t cols);
		Matrix(uint32_t rows, uint32_t cols, double matrix[]);
		Matrix(const Matrix& matrix);
		~Matrix();

		double& operator()(uint32_t i, uint32_t j);

		void operator+=(const Matrix& matrix);
		void operator-=(const Matrix& matrix);
		void operator*=(double value);
		void operator=(const Matrix& matrix);
		void Copy(Matrix* matrix);

		Matrix FastMul(const Matrix& matrix);
		Matrix operator+(const Matrix& matrix);
		Matrix operator-(const Matrix& matrix);
		Matrix operator*(double value);
		Matrix operator*(const Matrix& matrix);
		Vector operator*(const Vector& value);

		void AssignCol(const Vector& vec, int col);
		Vector GetCol(uint32_t col);

		friend class Vector;
		friend MATH_API double Magnitude(const Matrix& matrix);
		friend MATH_API Matrix Transpose(const Matrix& matrix);
		friend MATH_API void Input(Matrix & matrix);
		friend MATH_API void Print(const Matrix & matrix);
		friend MATH_API int Determinant(const Matrix& matrix, int n);
		friend MATH_API Matrix Cofactor(const Matrix& matrix, int p, int q);
		friend MATH_API Matrix Adjoint(const Matrix& matrix);
		friend MATH_API Matrix Inverse(const Matrix& matrix);
	};

}

#endif