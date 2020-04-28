#pragma once
namespace integrals {
	double RectangleMethod(double(*F)(double), double high, double low, int n);

	double TrapezoidMethod(double(*F)(double), double high, double low, int n);

	double ParabolaMethod(double(*F)(double), double high, double low, int n);
}