#pragma once
#include <malloc.h>

class MethodResolver
{

public:
	MethodResolver();
	virtual void ApplyMethod() = 0;
	virtual ~MethodResolver();
protected:
	void PrepareBorderConditions();
	double f(double x, double y);
	double *x, *y;
	const double eps=1E-3;
	const int N = 1024;
	const double h = 1.0 / N;
	double **u, **u_prev;
	double w = 2;
};

