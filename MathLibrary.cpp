#include "Vector3D.h"
#include "MathFunctions.h"
#include "Matrix.h"

int main() {
	Vector3D vec(5, 5, 5);
	Matrix mat1(4, 3);

	mat1.Input();
	Matrix c = mat1 * vec;

	Matrix::PrintMatrix(c);

	return 0;
}