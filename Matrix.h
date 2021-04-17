#ifndef MATRIX_H_
#define MATRIX_H_

#include "MathLibrary.h"

namespace math {

	class Vector;

	MATH_API class Matrix {
	public:

		double* m_Matrix = nullptr;
		size_t m_Rows = 0;
		size_t m_Cols = 0;
		Matrix(size_t rows, size_t cols, double initValue = 0.0);
		Matrix(size_t rows, size_t cols, double matrix[]);
		Matrix(const Matrix& matrix);
		Matrix(Matrix&& matrix) noexcept;
		void Copy(const Matrix& matrix);
		~Matrix();

		double& operator()(size_t i, size_t j);

		void operator+=(const Matrix& matrix);
		void operator-=(const Matrix& matrix);
		void operator*=(double value);
		void operator=(const Matrix& matrix);
		void operator=(Matrix&& matrix) noexcept;

		Matrix operator+(const Matrix& matrix);
		Matrix operator-(const Matrix& matrix);
		Matrix operator*(double value);
		Matrix operator*(const Matrix& matrix);
		Vector operator*(const Vector& value);

		void AssignCol(const Vector& vector, size_t col);
		void AssignRow(const Vector& vector, size_t row);
		void AppendCol(const Vector& vector);
		void AppendRow(const Vector& vector);
		void RemoveCol(size_t col);
		void RemoveRow(size_t row);
		Vector GetCol(size_t col);
		Vector GetRow(size_t row);

		void Clear();

		friend class Vector;
		friend MATH_API double Magnitude(const Matrix& matrix);
		friend MATH_API Matrix Transpose(const Matrix& matrix);
		friend MATH_API void Input(Matrix& matrix);
		friend MATH_API void Print(const Matrix& matrix);
		friend MATH_API int64_t Determinant(const Matrix& matrix, int64_t n);
		friend MATH_API Matrix Cofactor(const Matrix& matrix, int64_t p, int64_t q);
		friend MATH_API Matrix Adjoint(const Matrix& matrix);
		friend MATH_API Matrix Inverse(const Matrix& matrix);
		friend MATH_API Vector GaussianElimination(const Matrix& matrix, const Vector& vector);
		friend MATH_API int64_t ForwardElimination(const Matrix& matrix);
		friend MATH_API Vector BackSubstitutian(Matrix& matrix);
	};
}

#endif