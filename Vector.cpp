#include "Vector.h"
#include <iostream>

Vector::Vector()
{
	m_array = new double[1];
	m_array[0] = 0;
	size = 0;
}

Vector::Vector(unsigned int size) : size(size)
{
	m_array = new double[this->size];
	for (unsigned int i = 0; i < this->size; i++)
	{
		m_array[i] = 0;
	}
}

Vector::Vector(unsigned int size, double value) : size(size)
{
	m_array = new double[this->size];
	for (unsigned int i = 0; i < this->size; i++)
	{
		m_array[i] = value;
	}
}

Vector::Vector(unsigned int size, double * value) : size(size)
{
	m_array = new double[this->size];
	for (unsigned int i = 0; i < this->size; i++)
	{
		m_array[i] = value[i];
	}
}

Vector::~Vector()
{
	
}

void Vector::PrintCoords()
{
	for (unsigned int i = 0; i < size; i++)
	{
		printf_s("%.12lf\n",m_array[i]);
	}
}

void Vector::PrintCoords(const Vector & vec)
{
	for (unsigned int i = 0; i < vec.size; i++)
	{
		printf_s("%.12lf\n", vec.m_array[i]);
	}
}

Vector Vector::operator=(const Vector & vec)
{
	delete[] this->m_array;
	this->m_array = new double[vec.size];
	this->size = vec.size;
	for (unsigned int i = 0; i < this->size; i++)
	{
		m_array[i] = vec.m_array[i];
	}

	return *this;
}

void Vector::operator+=(const Vector & vec)
{
	if (this->size != vec.size)
		return;
	for (unsigned int i = 0; i < this->size; i++)
	{
		this->m_array[i] += vec.m_array[i];
	}
}

void Vector::operator-=(const Vector & vec)
{
	if (this->size != vec.size)
		return;
	for (unsigned int i = 0; i < this->size; i++)
	{
		this->m_array[i] -= vec.m_array[i];
	}
}

void Vector::operator*=(double value)
{
	for (unsigned int i = 0; i < this->size; i++)
	{
		this->m_array[i] *= value;
	}
}

double Vector::operator*(const Vector & vec)
{
	if (this->size != vec.size)
		return NULL;
	double r = 0;
	for (unsigned int i = 0; i < this->size; i++)
	{
		r += this->m_array[i] * vec.m_array[i];
	}
	return r;
}

Vector Vector::operator*(double value)
{
	Vector r(this->size);
	for (unsigned int i = 0; i < this->size; i++)
	{
		r.m_array[i] = this->m_array[i] * value;
	}
	return r;
}

Vector Vector::operator+(const Vector & vec)
{
	if (this->size != vec.size)
		return NULL;
	Vector r(this->size);
	for (unsigned int i = 0; i < this->size; i++)
	{
		r.m_array[i] = this->m_array[i] + vec.m_array[i];
	}
	return r;
}

Vector Vector::operator-(const Vector & vec)
{
	if (this->size != vec.size)
		return NULL;
	Vector r(this->size);
	for (unsigned int i = 0; i < this->size; i++)
	{
		r.m_array[i] = this->m_array[i] - vec.m_array[i];
	}
	return r;
}

Vector & Vector::Normilize()
{
	*this *= (1 / this->Length());
	return *this;
}

double Vector::Length() const
{
	double length = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		length += this->m_array[i] * this->m_array[i];
	}
	return sqrtf(length);
}

double& Vector::operator[](unsigned int index)
{
	return this->m_array[index];
}

bool Vector::operator>(const Vector & vec)
{
	return (this->Length() > vec.Length());
}

bool Vector::operator<(const Vector & vec)
{
	return (this->Length() < vec.Length());
}

bool Vector::operator>=(const Vector & vec)
{
	return (this->Length() >= vec.Length());
}

bool Vector::operator<=(const Vector & vec)
{
	return (this->Length() <= vec.Length());
}

bool Vector::operator==(const Vector & vec)
{
	return (this->Length() == vec.Length());
}

bool Vector::operator!=(const Vector & vec)
{
	return (this->Length() != vec.Length());
}
