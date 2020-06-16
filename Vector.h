#pragma once
#include <vector>

class Vector {
public:
	double* m_array;
	unsigned int size = 0;

	Vector();
	Vector(unsigned int size);
	Vector(unsigned int size,double value);
	Vector(unsigned int size,double* value);
	~Vector();

	void PrintCoords();
	static void PrintCoords(const Vector& vec);

	Vector operator =(const Vector& vec);
	void operator +=(const Vector& vec);
	void operator -=(const Vector& vec);
	void operator *=(double value);

	double operator *(const Vector& vec);
	Vector operator *(double value);
	Vector operator +(const Vector& vec);
	Vector operator -(const Vector& vec);
	Vector& Normilize();

	double Length() const;

	double& operator[](unsigned int index);

	bool operator>(const Vector& vec);
	bool operator<(const Vector& vec);
	bool operator>=(const Vector& vec);
	bool operator<=(const Vector& vec);
	bool operator==(const Vector& vec);
	bool operator!=(const Vector& vec);
};