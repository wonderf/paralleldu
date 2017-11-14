#pragma once

#include <iostream>
#include <fstream>

class MethodResolver
{

public:
	MethodResolver();
	virtual void ApplyMethod() = 0;
	virtual ~MethodResolver();
	
protected:
	double *x, *y;
	double **u, **u_prev;

	void PrepareBorderConditions();
	void PrintStat(double elapsed, int iteration);
	void WriteStatToFile(double *x,double *y,double **u,char *name);


	double f(const double &x,const double &y);
	
	const double eps=1E-3;
	const int N = 64;
	const double h = 1.0 / N;
	
	double w = 2;
};

