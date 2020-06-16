#pragma once
#include "MathLibrary.h"
#include <iostream>

class Vector3D {
private:
	double x, y, z;
	
public:

	Vector3D();
	Vector3D(double x, double y, double z);

	void PrintCoords();
	static void PrintCoords(const Vector3D& vec3);

	Vector3D operator =(const Vector3D& vec3);
	void operator +=(const Vector3D& vec3);
	void operator -=(const Vector3D& vec3);
	void operator /=(const Vector3D& vec3);
	void operator *=(double value);

	double operator *(const Vector3D& vec3);
	Vector3D operator *(double value);
	Vector3D operator +(const Vector3D& vec3);
	Vector3D operator -(const Vector3D& vec3);
	Vector3D operator /(const Vector3D& vec3);
	Vector3D operator ~();
	Vector3D& Normilize();

	double Length() const;

	double& operator[](unsigned int index);

	bool operator>(const Vector3D& vec3);
	bool operator<(const Vector3D& vec3);
	bool operator>=(const Vector3D& vec3);
	bool operator<=(const Vector3D& vec3);
	bool operator==(const Vector3D& vec3);
	bool operator!=(const Vector3D& vec3);
};