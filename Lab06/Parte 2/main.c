#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double 				sum;
long long int 		n;
int 				thread_count;
pthread_mutex_t 	brabo;


void* Thread_sum(void* rank){
    long my_rank = (long) rank;
    double factor;
	double my_sum = 0.0;
    long long i;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0 )    /*my_first_i is even*/
        factor = 1.0;
    else                         /* my_first_i is odd */
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor){my_sum += factor/(2 * i + 1);}

	pthread_mutex_lock(&brabo);
	sum += my_sum;
	pthread_mutex_unlock(&brabo);
    return NULL;
}     /*Thread_sum*/

int main(int argc, char* argv[]) {
	pthread_t threadsss[thread_count];
	thread_count = strtol(argv[1], NULL, 10);
	
	n = strtol(argv[2], NULL, 10);
	sum = 0.0;
	
	for (long t = 0; t <= thread_count; t++)
	{
		int rc = pthread_create (&threadsss[t], NULL, Thread_sum, (void*) t);
		if (rc) {printf("EROUISJHAODIKA - F"); exit (-1);}
	}

    for (int t = 0; t < thread_count; t++){
        pthread_join(threadsss[t], NULL);
    }

	pthread_mutex_destroy(&brabo);
	
	printf("PIIIII = %f", 4*sum);
	printf("\n");
	pthread_exit(NULL);
}
