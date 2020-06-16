#include "Vector3D.h"
#include "MathFunctions.h"
#include "Matrix.h"
#include <vector>
#include "Vector.h"


double Func(Matrix* B, Vector* X, int i) {
	double temp = 0;
	for (unsigned int j = 0; j < B->n; j++)
	{
		temp += B->operator()(j,i) * X->operator[](j);
	}
	return temp;
}

Vector ZeydelMethod(Matrix* A, Vector b, double E, unsigned int *n) {
	Matrix B(A->n, A->m);
	Vector c(3);
	std::vector<Vector> M;
	for (uint32_t i = 0; i < A->n; i++)
	{
		for (uint32_t j = 0; j < A->m; j++)
		{
			if (i == j)
				B.operator()(j, i) = 0;
			else
				B.operator()(j, i) = -A->operator()(i, j) / A->operator()(i, i);
		}

		c[i] = b[i] / A->operator()(i, i);

	}

	M.push_back(Vector(3,1));
	uint32_t k = 1;
	while (true) {
		k++;
		Vector temp(3, 0.0);
		for (uint32_t i = 0; i < A->n; i++)
		{
			temp[i] = c[i] + Func(&B, &M[0], i);
		}
		M.push_back(temp);
		double error = (M[1] - M[0]).Length() / M[0].Length();
		if ( error < E)
			break;
		M.erase(M.begin());
	}

	*n = k - 1;
	return M.back();
}

Vector SimpleIterations(Matrix* A, Vector b,double E,unsigned int *n) {
	Matrix B(A->n, A->m);
	Vector c(3);
	std::vector <Vector> x;

	for (uint32_t i = 0; i < A->n; i++)
	{
		for (uint32_t j = 0; j < A->m; j++)
		{
			if (i == j)
				B.operator()(j, i) = 0;
			else
				B.operator()(j, i) = -A->operator()(i, j) / A->operator()(i, i);
		}
		
		c[i] = b[i] / A->operator()(i,i);
		
	}
	x.push_back(Vector(3, 1));

	uint32_t k = 1;
	while(true){
		k++;
		x.push_back(Vector((B * x[0]) + c));
		double error = ((x[0] - x[1]).Length()) / x[1].Length();
		if (error < E)
			break;
		x.erase(x.begin());
	}

	*n = k - 1;
	return x.back();
}

Vector GradientDescent(Matrix* A, Vector* b, double E, unsigned int *n) {
	Vector x(3,1);
	Vector w = *A * x - *b;
	uint32_t counter = 0;
	while (true) {
		counter++;
		Vector Aw = *A * w;
		double a = (w * w) / (Aw * w);
		x = x - w * a;
		w = w - Aw * a;
		if (a * w.Length() < E)
			break;
	}
	*n = counter;
	return x;
}

int main() {

	double matArr[9] = { 4,2,1,2,5,1,1,1,6 };
	double vecArr[3] = { 3,-2,6 };

	Matrix A(3, 3, matArr);
	Vector b(3,vecArr);
	double E = 1e-6;
	uint32_t n = 0;

	std::cout << "Simple Iterations\n";
	Vector result = SimpleIterations(&A, b, E,&n);
	result.PrintCoords();
	std::cout << n << std::endl;

	std::cout << "\nZeydel method\n";
	Vector result2 = ZeydelMethod(&A, b, E, &n);
	result2.PrintCoords();
	std::cout << n << std::endl;

	std::cout << "\nGradient Descent\n";
	Vector result1 = GradientDescent(&A, &b, E, &n);
	result1.PrintCoords();
	std::cout << n << std::endl;

	return 0;
}