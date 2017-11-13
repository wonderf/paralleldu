#include "Relaxation.h"



Relaxation::Relaxation()
{
	
}


Relaxation::~Relaxation()
{
}

void Relaxation::ApplyMethod()
{
	double max_error;
	double error;
	double prev;
	int it_count = 1;
	double start, end, elapsed;

	//start = clock();
	start = omp_get_wtime();
	FILE *err_f = fopen("err.dat", "w");
	if (f == NULL)
		printf("FAILED TO CREATE FILE err.dat");
	do {
		max_error = 0;
		//	#pragma omp parallel for num_threads(16)
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				//prev = u[i][j];
				prev = (x[i] * x[i] - x[i] + 1) * (y[j] * y[j] - y[j] + 1);
				u[i][j] = w / 4 * (u[i - 1][j] + u_prev[i + 1][j] + u[i][j - 1] + u_prev[i][j + 1] - h * h * f(x[i], y[j])) + (1 - w) * u_prev[i][j];
				error = fabs(u[i][j] - prev);
				if (error > max_error)
					max_error = error;
				//		u_prev[i][j] = u[i][j];
			}
		}
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < N; j++) {
				u_prev[i][j] = u[i][j];
			}
		}
		//	printf("Iteration: %d, max error: %lf\n", it_count, max_error);
		//todo c++ write to file
		fprintf(err_f, "Iteration: %d, max error: %lf\n", it_count, max_error);
		it_count++;
	} while (max_error > eps);


	end = omp_get_wtime();
	//elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
	elapsed = end - start;

	printf("PROCESS FINISHED\n");
	//fprintf(err_f, "PROCESS FINISHED\n");
	printf("ELAPSED: %lf\n", elapsed);
	printf("ITERATION COUNT: %d\n", it_count);
	fprintf(err_f, "ELAPSED: %lf\n", elapsed);

	fclose(err_f);

	FILE *output = fopen("result_Relaxation.dat", "w");
	if (f == NULL)
		printf("FAILED TO CREATE FILE result.dat");

	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			fprintf(output, "%lf %lf %lf\n", x[i], y[j], u[i][j]);
		}
	}

	fclose(output);
}
