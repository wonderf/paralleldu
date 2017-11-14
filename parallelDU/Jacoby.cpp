#include "Jacoby.h"



Jacoby::Jacoby()
{
}


Jacoby::~Jacoby()
{
}

void Jacoby::ApplyMethod()
{
	PrepareBorderConditions();
	double max_error;
	double error;
	double prev;
	int it_count = 1;
	double start, end, elapsed;
	
	//start = clock();
	start = clock();
	/*
	FILE *err_f = fopen("err.dat", "w");
	if (f == NULL)
		printf("FAILED TO CREATE FILE err.dat");
	*/
	do {
		max_error = 0;
		//	#pragma omp parallel for num_threads(16)
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				
				prev = (x[i] * x[i] - x[i] + 1) * (y[j] * y[j] - y[j] + 1);
				u[i][j] = 0.25 * (u_prev[i-1][j] + u_prev[i + 1][j] + u_prev[i][j - 1] + u_prev[i][j + 1] - h * h * f(x[i], y[j]));
				error = fabs(u[i][j] - prev);
				if (error > max_error)
					max_error = error;
				
			}
		}
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				u_prev[i][j] = u[i][j];
			}
		}
		//todo c++ write to file
		//fprintf(err_f, "Iteration: %d, max error: %lf\n", it_count, max_error);
		it_count++;
	} while (max_error > eps);


	end = clock();
	//elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
	elapsed = end - start;

	PrintStat(elapsed, it_count);
	WriteStatToFile(x, y, u,"jacoby.ans");
}
