#include "Integrals.h"
#include <math.h>

namespace integrals {
	double RectangleMethod(double(*F)(double), double high, double low, int n) {
		double S = 0;
		double step = (high - low) / n;
		double deltaxval = low;
		for (int i = 0; i < n; i++)
		{
			S += step * (F(deltaxval));
			deltaxval += step;
		}
		return fabs(S);
	}

	double TrapezoidMethod(double(*F)(double), double high, double low, int n) {
		double S = 0;
		double step = (high - low) / n;
		double deltaxval = low;
		double a, b;
		for (int i = 0; i < n; i++)
		{
			a = F(deltaxval);
			b = F(deltaxval + step);
			S += ((a + b) / 2.) * step;
			deltaxval += step;
		}
		return fabs(S);
	}

	double ParabolaMethod(double(*F)(double), double high, double low, int n) {
		double S = 0;
		double step = (high - low) / n;
		double deltaxval = low;
		double a, b, c;
		for (int i = 0; i < n; i++)
		{
			a = deltaxval;
			b = deltaxval + step;
			c = (a + b) / 2.;
			S += (b - a) / 6. * (F(a) + 4. * F(c) + F(b));
			deltaxval += step;
		}
		return fabs(S);
	}
}