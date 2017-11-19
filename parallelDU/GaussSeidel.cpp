#include "GaussSeidel.h"



GaussSeidel::GaussSeidel()
{
}


GaussSeidel::~GaussSeidel()
{
}

void GaussSeidel::ApplyMethod()
{
	double max_error;
	double error;
	double prev;
	int it_count = 1;
	std::cout << it_count << std::endl;
	double start, end, elapsed;

	start = clock();
	//start = omp_get_wtime();
	double** ut = new double*[N + 1];
	for (int i = 0; i < N + 1; i++)
		ut[i] = new double[N + 1];
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			ut[i][j] = (x[i] * x[i] - x[i] + 1) * (y[j] * y[j] - y[j] + 1);
		}
	}

	do {
		max_error = 0;
		//	#pragma omp parallel for num_threads(16)
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {

				
				u[i][j] = 0.25 * (u[i - 1][j] + u[i + 1][j] + u[i][j - 1] + u[i][j + 1] - h * h * f(x[i], y[j]));
				
				error = fabs(u[i][j] - ut[i][j]);
				if (error > max_error)
					max_error = error;

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
	WriteStatToFile(x, y, u,"gaussseidel.ans");
}
