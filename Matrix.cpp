#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "MathFunctions.h"
#include "Timer.h"

using namespace math;

Matrix::Matrix(uint32_t m, uint32_t n) : n(n),m(m)
{
#ifdef _DEBUG
	std::cout << "Matrix is created\n";
#endif 

	uint32_t size = m * n;
	m_matrix = new double[size];
	for (uint32_t i = 0; i < size; i++)
	{
		m_matrix[i] = 0;
	}
}

Matrix::Matrix(uint32_t m, uint32_t n,double matrix[]) : n(n),m(m)
{
#ifdef _DEBUG
	std::cout << "Matrix is created\n";
#endif 

	uint32_t size = m * n;
	m_matrix = new double[size];
	for (uint32_t i = 0; i < size; i++)
	{
		m_matrix[i] = matrix[i];
	}
}

Matrix::Matrix(const Matrix & matrix) : n(matrix.n),m(matrix.m)
{
#ifdef _DEBUG
	std::cout << "Matrix is copied\n";
#endif 

	m_matrix = new double[m * n];

	uint32_t size = m * n;
	for (uint32_t i = 0; i < size; i++)
	{
		m_matrix[i] = matrix.m_matrix[i];
	}
}

Matrix::~Matrix()
{
#ifdef _DEBUG
	std::cout << "Matrix is destroyed " << m_matrix << std::endl;
#endif
	delete[] m_matrix;
	m_matrix = nullptr;
	delete[] complete;
	complete = nullptr;
}

double& Matrix::operator()(uint32_t i, uint32_t j)
{
	return m_matrix[i * m + j];
}

void Matrix::operator+=(Matrix & matrix)
{
	uint32_t size = m * n;
	for (uint32_t i = 0; i < size; i++)
	{
		m_matrix[i] += matrix.m_matrix[i];
	}
}

void Matrix::operator-=(Matrix & matrix)
{
	uint32_t size = m * n;
	for (uint32_t i = 0; i < size; i++)
	{
		m_matrix[i] -= matrix.m_matrix[i];
	}
}

void Matrix::operator*=(double value)
{
	uint32_t size = m * n;
	for (uint32_t i = 0; i < size; i++)
	{
		m_matrix[i] *= value;
	}
}

void Matrix::operator=(Matrix& matrix)
{
#ifdef _DEBUG
	std::cout << "Matrix is copied\n";
#endif 
	m = matrix.m;
	n = matrix.n;
	m_matrix = new double[m * n];

	uint32_t size = m * n;
	for (uint32_t i = 0; i < size; i++)
	{
		m_matrix[i] = matrix.m_matrix[i];
	}
}

Matrix math::Matrix::FastMul(Matrix & matrix)
{
	Timer timer;
	if (m == matrix.n) {
		Matrix C(m, matrix.n);
		for (uint32_t i = 0; i < m; ++i)
		{
			double * c = C.m_matrix + i * n;
			for (uint32_t j = 0; j < n; ++j)
				c[j] = 0;
			for (uint32_t k = 0; k < m; ++k)
			{
				const double * b = matrix.m_matrix + k * n;
				double a = m_matrix[i*m + k];
				for (uint32_t j = 0; j < n; ++j)
					c[j] += a * b[j];
			}
		}
		return C;
	}
	return Matrix(1, 1);
}

Matrix Matrix::operator+(Matrix & matrix)
{
	Matrix c(m, n);
	uint32_t size = m * n;
	for (uint32_t i = 0; i < size; i++)
	{
		c.m_matrix[i] = m_matrix[i] + matrix.m_matrix[i];
	}
	return c;
}

Matrix Matrix::operator-(Matrix & matrix)
{
	Matrix c(m, n);
	uint32_t size = m * n;
	for (uint32_t i = 0; i < size; i++)
	{
		c.m_matrix[i] = m_matrix[i] - matrix.m_matrix[i];
	}
	return c;
}

Matrix Matrix::operator*(double value)
{
	Matrix c(m, n);
	uint32_t size = m * n;
	for (uint32_t i = 0; i < size; i++)
	{
		c.m_matrix[i] = m_matrix[i] * value;
	}
	return c;
}

Vector Matrix::operator*(Vector& value)
{
	if (m == value.m_size) {
		Vector c(m);
		for (uint32_t i = 0; i < m; i++)
		{
			for (uint32_t j = 0; j < n; j++)
			{
				c.m_array[i] += operator()(i, j) * value.m_array[j];
			}
		}
		return c;
	}
}

//@Deprecated!
//#include "ThreadPool.h"
//Matrix Matrix::operator*(Matrix& matrix)
//{
//	std::unique_lock<std::mutex> lk(cv_m);	
//	Timer timer;
//	if (m == matrix.n) {
//		std::shared_ptr<Matrix> c(new Matrix(m, matrix.n));
//		std::shared_ptr<Matrix> b(new Matrix(matrix));
//		std::shared_ptr<Matrix> a(new Matrix(*this));
//		uint32_t th = ThreadPool::Instance()->num_Threads;
//		uint32_t counter = 0;
//		uint32_t offsetM = m / th;
//		uint32_t newM = 0;
//		if (offsetM == 0) { offsetM = 1; th = m; }
//		complete = new bool[th];
//		for (uint32_t i = 0; i < th; i++)
//		{
//			ThreadPool::Instance()->enqueue([=] {
//				for (uint32_t i = newM; i < newM + offsetM; i++) {
//					for (uint32_t j = 0; j < n; j++) {
//						c->m_matrix[i * m + j] = 0;
//						for (uint32_t k = 0; k < m; k++) {
//							c->m_matrix[i * m + j] += a->m_matrix[i * m + k] * b->m_matrix[k * m + j];
//						}
//					}
//				}
//				complete[i] = true;
//				cv.notify_all();
//			});
//			newM += offsetM;
//		}
//		cv.wait(lk, [=] {
//			bool check = false;
//			for (uint32_t i = 0; i < th; i++)
//			{
//				check = complete[i];
//			}
//			return check;
//		});
//		for (uint32_t i = 0; i < th; i++)
//		{
//			complete[i] = false;
//		}
//		return *c;
//	}
//}

Matrix Matrix::operator*(Matrix& matrix)
{
	Timer timer;
	if (m == matrix.n) {
		Matrix C(m, matrix.n);
		for (uint32_t i = 0; i < m; ++i) {
			uint32_t im = i * m;
			double* a = m_matrix + im;
			for (uint32_t j = 0; j < n; ++j) {
				double* c = C.m_matrix + im + j;
				double* b = matrix.m_matrix + j;
				*c = 0;
				for (uint32_t k = 0; k < m; ++k) {
					*c += a[k] * *(b + (k * m));
				}
			}
		}
		return C;
	}
	return Matrix(1,1);
}

//Matrix & Matrix::Inverse(Matrix & matrix)
//{
//	
//}

void Matrix::AssignCol(Vector vec, int col)
{
	if (vec.m_size != m) {
		return;
	}
	for (uint32_t i = 0; i < m; i++)
	{
		operator()(i,col) = vec[i];
	}
}

Vector Matrix::GetCol(uint32_t col)
{
	if (col < n) {
		Vector temp(m);
		for (uint32_t i = 0; i < m; i++)
		{
			temp[i] = operator()(i, col);
		}
		return temp;
	}
}