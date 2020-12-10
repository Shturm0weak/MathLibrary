#pragma once
#include "MathLibrary.h"

namespace math {

	namespace integrals {

		MATH_API double RectangleMethod(double(*F)(double), double high, double low, int n);

		MATH_API double TrapezoidMethod(double(*F)(double), double high, double low, int n);

		MATH_API double ParabolaMethod(double(*F)(double), double high, double low, int n);

	}

}