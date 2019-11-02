#include "pch.h"
#include "Vector3D.h"
#include <math.h>

Vector3D::Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

double* Vector3D::GetCoords() {
	double* coords = (double*)malloc(3 * sizeof(double));
	coords[0] = this->x;
	coords[1] = this->y;
	coords[2] = this->z;
	return coords;
}

double* Vector3D::GetCoords(const Vector3D& vec3) {
	double* coords = (double*)malloc(3 * sizeof(double));
	coords[0] = vec3.x;
	coords[1] = vec3.y;
	coords[2] = vec3.z;
	return coords;
}

void Vector3D::PrintCoords()
{
	printf("Coords:\nX: %.3lf\nY: %.3lf\nZ: %.3lf\n",this->x,this->y,this->z);
}

void Vector3D::PrintCoords(const Vector3D & vec3)
{
	printf("Coords:\nX: %.3lf\nY: %.3lf\nZ: %.3lf\n", vec3.x, vec3.y, vec3.z);
}

void Vector3D::SetCoords(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3D::operator=(const Vector3D& vec3) {
	this->x = vec3.x;
	this->y = vec3.y;
	this->z = vec3.z;
}
Vector3D Vector3D::operator+(const Vector3D& vec3)
{
	return Vector3D(this->x +vec3.x, this->y + vec3.y, this->z + vec3.z);
}

Vector3D Vector3D::operator-(const Vector3D& vec3)
{
	return Vector3D(this->x - vec3.x, this->y - vec3.y, this->z - vec3.z);
}

Vector3D Vector3D::operator*(const Vector3D& vec3)
{
	return Vector3D(this->x * vec3.x, this->y * vec3.y, this->z * vec3.z);
}

Vector3D Vector3D::operator/(const Vector3D& vec3)
{
	return Vector3D(this->x / vec3.x, this->y / vec3.y, this->z / vec3.z);
}

Vector3D Vector3D::operator~()
{
	double x = (this->y * 1 + this->z * 1) /  (-this->x);
	return Vector3D(x,1,1);
}

void Vector3D::operator+=(const Vector3D& vec3)
{
	this->x += vec3.x;
	this->y += vec3.y;
	this->z += vec3.z;
}

void Vector3D::operator-=(const Vector3D& vec3)
{
	this->x -= vec3.x;
	this->y -= vec3.y;
	this->z -= vec3.z;
}

void Vector3D::operator/=(const Vector3D& vec3)
{
	this->x /= vec3.x;
	this->y /= vec3.y;
	this->z /= vec3.z;
}

void Vector3D::operator*=(const Vector3D& vec3)
{
	this->x *= vec3.x;
	this->y *= vec3.y;
	this->z *= vec3.z;
}

double Vector3D::operator!() const {
	return sqrt(x*x + y*y + z*z);
}

bool Vector3D::operator>(const Vector3D& vec3)
{
	if (this->operator!() > vec3.operator!())
		return true;
	else
		return false;
}

bool Vector3D::operator<(const Vector3D & vec3)
{
	if (this->operator!() < vec3.operator!())
		return true;
	else
		return false;
}

bool Vector3D::operator>=(const Vector3D & vec3)
{
	if (this->operator!() >= vec3.operator!())
		return true;
	else
		return false;
}

bool Vector3D::operator<=(const Vector3D & vec3)
{
	if (this->operator!() <= vec3.operator!())
		return true;
	else
		return false;
}

bool Vector3D::operator==(const Vector3D & vec3)
{
	if (this->operator!() == vec3.operator!())
		return true;
	else
		return false;
}

bool Vector3D::operator!=(const Vector3D & vec3)
{
	if (this->operator!() != vec3.operator!())
		return true;
	else
		return false;
}