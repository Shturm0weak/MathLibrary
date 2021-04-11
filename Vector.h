#ifndef VECTOR_H_
#define VECTOR_H_

#include "MathLibrary.h"

namespace math {

	class Matrix;

	MATH_API class Vector {
	private:

		double* m_Array = nullptr;
		size_t m_Size = 0;
	public:

		Vector(size_t size = 0, double value = 0.0);
		Vector(size_t size, double* value);
		Vector(const Vector& vector);
		~Vector();

		void operator=(const Vector& vector);
		void operator=(Vector&& vector) noexcept;
		void operator+=(const Vector& vector);
		void operator-=(const Vector& vector);
		void operator*=(double value);

		double operator*(const Vector& vector);
		Vector operator*(const Matrix& matrix);
		Vector operator*(double value);
		Vector operator+(const Vector& vector);
		Vector operator-(const Vector& vector);

		double Length() const;

		double& operator[](size_t index);

		bool operator<(const Vector& vector);

		size_t GetSize() { return m_Size; }

		void Clear();

		void Erase(size_t index);
		void Join(Vector& vector, size_t index);

		friend class Matrix; 
		friend MATH_API void Print(const Vector& vector);
		friend MATH_API Vector Normalize(Vector& vector);
		friend MATH_API Vector GaussianElimination(const Matrix& matrix, const Vector& vector);
	};

}

#endif