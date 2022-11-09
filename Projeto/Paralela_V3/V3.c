#include <stdio.h>
#include <stdlib.h>
#include <omp.h> 

long long int      	pedaco;
long double        	tysum;
int                	QNTD_THREADS;
pthread_mutex_t    	brabo;
long double			soma;

long long int fats[1000000];

unsigned long long int fat(int n) 
{
    if (n == 0) fats[n] = 1;
    else fats[n] = n * fat(n-1);
	//if (fats[n] < 0) fats[n] *= -1;
	return fats[n];
}

void taylor(long long* global_result_p){
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    long long my_pedaco = pedaco /thread_count;
    long long my_first_i = my_pedaco * my_rank;
    long long my_last_i = my_first_i + my_pedaco;
    long double my_tysum;
    int i;

     for (i = my_first_i; i < my_last_i; i++) my_tysum += 1 / (double) fats[i];

#    pragma omp critical
    *global_result_p += my_tysum;
}


int main(int argc, char *argv[])
{
    long long global_result = 0.0;
    int n;
    
    QNTD_THREADS = strtol(argv[1], NULL, 10);
    pedaco = strtol(argv[2], NULL, 10);

    fat(pedaco);

 #  pragma omp parallel num_threads(QNTD_THREADS)
    taylor(&global_result);

    printf("resultado: %.33Lf \n", global_result);
    
}
 
