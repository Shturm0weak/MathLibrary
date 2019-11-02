#include "pch.h"
#include "Vector3D.h"

int main(){
	Vector3D Avec3(1,2,3);
	Vector3D Bvec3(8, -2, 5);
	Vector3D* vec = new Vector3D(5, 3, -7);
	Vector3D Cvec3(1, 2, 3);
	Cvec3 += Avec3 + (Avec3 * Bvec3) - Bvec3 + Vector3D(1,2,3) / Bvec3;

	Vector3D::PrintCoords(~Cvec3);

	Vector3D::PrintCoords(~*vec);

	Vector3D::PrintCoords(~Avec3);

	std::cout << (*vec>=(Cvec3));
}