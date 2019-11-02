#pragma once

#include <iostream>

class Vector3D {
private:
	double x, y, z;
	
public:

	Vector3D();
	Vector3D(double x, double y, double z);

	double* GetCoords();
	static double* GetCoords(const Vector3D& vec3);

	void PrintCoords();
	static void PrintCoords(const Vector3D& vec3);

	void SetCoords(double x,double y,double z);

	void operator =(const Vector3D& vec3);
	void operator +=(const Vector3D& vec3);
	void operator -=(const Vector3D& vec3);
	void operator *=(const Vector3D& vec3);
	void operator /=(const Vector3D& vec3);
	Vector3D operator +(const Vector3D& vec3);
	Vector3D operator -(const Vector3D& vec3);
	Vector3D operator *(const Vector3D& vec3);
	Vector3D operator /(const Vector3D& vec3);
	Vector3D operator ~();
	double operator!() const;
	bool operator>(const Vector3D& vec3);
	bool operator<(const Vector3D& vec3);
	bool operator>=(const Vector3D& vec3);
	bool operator<=(const Vector3D& vec3);
	bool operator==(const Vector3D& vec3);
	bool operator!=(const Vector3D& vec3);
};