
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long long int      	pedaco;
long double        	tysum;
int                	QNTD_THREADS;
pthread_mutex_t    	brabo;
long double			soma;


long long int fats[1000000] = {0};

long long int fat(int n) 
{
    if (n == 0) fats[n] = 1;
    else fats[n] = n * fat(n-1);
	return fats[n];
}

void *taylor(void* rank) 
{   
    long my_rank = (long) rank;
    long long i;
	long long my_pedaco = pedaco / QNTD_THREADS;
	long long my_first_i = my_pedaco * my_rank;
	long long my_last_i = my_first_i + my_pedaco;
	long double my_tysum = 0.0;

//	printf("mypedaco = %lld\t", my_pedaco);
//	printf("firsti = %lld\t", my_first_i);
//	printf("lasti = %lld\t", my_last_i);
//	printf("myrank = %ld\n", my_rank);

    for (i = my_first_i; i < my_last_i; i++) 
	{
		my_tysum += 1 / (double) fat(i);
	}
	pthread_mutex_lock(&brabo);
	tysum += my_tysum;
	pthread_mutex_unlock(&brabo);

    return NULL;
}

int main(int argc, char *argv[])
{
    QNTD_THREADS = strtol(argv[1], NULL, 10);
    pthread_t v_thread[QNTD_THREADS];

    pedaco = strtol(argv[2], NULL, 10);

    for (long t = 0; t <= QNTD_THREADS; t++){
        int rc = pthread_create(&v_thread[t], NULL, taylor, (void*) t);
        if (rc) {printf("EROUISJHAODIKA - F"); exit (-1);}
    }

    for (int t = 0; t < QNTD_THREADS; t++)
        pthread_join(v_thread[t], NULL);

    pthread_mutex_destroy(&brabo);
    printf("resultado: %.33Lf \n", tysum);
	pthread_exit(NULL);
}
