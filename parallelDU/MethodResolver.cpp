#include "MethodResolver.h"



MethodResolver::MethodResolver()
{
	double **u = (double**)malloc((N + 1) * sizeof(double*));
	double **u_prev = (double**)malloc((N + 1) * sizeof(double*));
	double *x = (double*)malloc((N + 1) * sizeof(double));
	double *y = (double*)malloc((N + 1) * sizeof(double));
	for (int i = 0; i < N + 1; i++) {

		u[i] = (double*)malloc((N + 1) * sizeof(double));
		u_prev[i] = (double*)malloc((N + 1) * sizeof(double));

		if (i == 0) {
			x[i] = 0;
			y[i] = 0;
		}
		else {
			x[i] = x[i - 1] + h;
			y[i] = y[i - 1] + h;
		}
	}

}


MethodResolver::~MethodResolver()
{
}

void MethodResolver::PrepareBorderConditions()
{
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			if (i == 0 || i == N)
				u[i][j] = y[j] * y[j] - y[j] + 1;
			else if (j == 0 || j == N)
				u[i][j] = x[i] * x[i] - x[i] + 1;
			else
				u[i][j] = 0;

			u_prev[i][j] = u[i][j];
		}
	}
}

double MethodResolver::f(double x,double y) {
	return 4 + 2 * x*x - 2 * x + 2 * y*y - 2 * y;
}