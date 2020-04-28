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

 void Vector3D::PrintCoords()
{
	printf("Coords:\nX: %.3lf\nY: %.3lf\nZ: %.3lf\n",this->x,this->y,this->z);
}

 void Vector3D::PrintCoords(const Vector3D & vec3)
{
	printf("Coords:\nX: %.3lf\nY: %.3lf\nZ: %.3lf\n", vec3.x, vec3.y, vec3.z);
}

 Vector3D Vector3D::operator=(const Vector3D& vec3) {
	this->x = vec3.x;
	this->y = vec3.y;
	this->z = vec3.z;

	return *this;
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
	return Vector3D(this->x * vec3.x , this->y * vec3.y , this->z * vec3.z);
}

 Vector3D Vector3D::operator*(double value)
 {
	 return Vector3D(this->x * value,this->y * value,this->z * value);
 }

 Vector3D Vector3D::operator/(const Vector3D& vec3)
{
	double x = this->y * vec3.z - vec3.y * this->z;
	double y = this->x * vec3.z - vec3.x * this->z;
	double z = this->x * vec3.y - vec3.x * this->y;
	return Vector3D(x,-y,z);
}

 void Vector3D::operator/=(const Vector3D& vec3)
{
	double x = this->y * vec3.z - vec3.y * this->z;
	double y = this->x * vec3.z - vec3.x * this->z;
	double z = this->x * vec3.y - vec3.x * this->y;
}

 void Vector3D::operator*=(const Vector3D & vec3)
 {
	 this->x *= vec3.x;
	 this->y *= vec3.y;
	 this->z *= vec3.z;
 }

 void Vector3D::operator*=(double value)
 {
	 this->x *= value;
	 this->y *= value;
	 this->z *= value;
 }

 Vector3D Vector3D::operator~()
{
	double x = (this->y * 1 + this->z * 1) /  (-this->x);
	return Vector3D(x,1,1);
}

 Vector3D& Vector3D::Normilize()
 {
	 *this *= (1 / this->Length());
	 return *this;
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

double Vector3D::Length() const {
	return sqrt(x*x + y*y + z*z);
}

double & Vector3D::operator[](unsigned int index)
{
	if (index == 0)
		return x;
	else if (index == 1)
		return y;
	else if (index == 2)
		return z;
}

bool Vector3D::operator>(const Vector3D& vec3)
{
	return (this->Length() > vec3.Length());
}

bool Vector3D::operator<(const Vector3D & vec3)
{
	return (this->Length() < vec3.Length());
}

bool Vector3D::operator>=(const Vector3D & vec3)
{
	return (this->Length() >= vec3.Length());
}

bool Vector3D::operator<=(const Vector3D & vec3)
{
	return (this->Length() <= vec3.Length());
}

bool Vector3D::operator==(const Vector3D & vec3)
{
	return (this->Length() == vec3.Length());
}

bool Vector3D::operator!=(const Vector3D & vec3)
{
	return (this->Length() != vec3.Length());
}