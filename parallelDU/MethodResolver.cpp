#include "MethodResolver.h"



MethodResolver::MethodResolver()
{
	
	double **u = new double* [N + 1];
	double **u_prev = new double*[N + 1];
	double *x = new double[N + 1];
	double *y = new double[N + 1];
	for (int i = 0; i < N + 1; i++) {

		u[i] = new double[N + 1];
		u_prev[i] = new double[N + 1];

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
	for (int count = 0; count < N+1; count++) {
		delete[]u[count];
		delete[]u_prev[count];
	}
	delete[] x;
	delete[] y;
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

void MethodResolver::PrintStat(double elapsed, int iteration)
{
	std::cout << "Process finished" << std::endl;
	std::cout << "Elapsed: " << elapsed << std::endl;
	std::cout << "Iteration count: " << iteration << std::endl;
	
	//fprintf(err_f, "ELAPSED: %lf\n", elapsed);
}

void MethodResolver::WriteStatToFile(double * x, double * y, double ** u)
{
	std::ofstream f("answer.dat");
	if (!f.is_open())
		std::cout << "FAILED TO CREATE FILE answer.dat" << std::endl;

	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			//fprintf(output, "%lf %lf %lf\n", x[i], y[j], u[i][j]);
			f << x[i] << y[j] << u[i][j] << std::endl;
		}
	}
	f.close();
}

double MethodResolver::f(double x,double y) {
	return 4 + 2 * x*x - 2 * x + 2 * y*y - 2 * y;
}