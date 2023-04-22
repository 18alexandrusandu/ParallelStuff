#include<omp.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
int main()
{
	srand(time(NULL));

	long long N = 100000000;

	
	double M = 6 * 1.3;
	
	double T1 = 0;
	for (int t = 0; t <=5; t++)
	{

		int t2 = 0;
		if (t <= 4)
			t2 = pow(2, t);
		else
			t2 = 12;

		omp_set_num_threads(t2);
		long var = 0;
		double start = omp_get_wtime();
		

#pragma omp parallel for schedule(static) reduction(+:var)
			for (long long i = 1; i < N; i++)
			{

				
				float x = ((float)rand()) / RAND_MAX;
				float y = ((float)rand()) / RAND_MAX;

				if (x * x + y * y <= 1)
					var += 1;

			}
		
			double end = omp_get_wtime();
			double time_elapsed = end - start;
			if (t == 0)
				T1 = time_elapsed;
			double speedup = T1 / time_elapsed;
			double eficiency = speedup / M;





		double pi = 4.0 * var / N;

		printf("the value of pi that was found is:%lf\n", pi);
		printf(" n_threads:%d time_elapsed:%lf speedup:%lf eficiency:%lf\n",t2,time_elapsed,speedup,eficiency );
	}



}