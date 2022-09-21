#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_T	3
#define m		9
#define n		9

int thread_count;
int A[m][n] = {	{1, 2, 3, 4,5,6,7,8,9},
				{4, 5, 6, 7,8,9,1,2,3},
				{3,7, 8, 9, 10,11,4,51,6},
				{12,13,14,15,16,12,5,2,39},
				{17,18,19,20,21,1251,6,1,75},
				{22,23,24,25,26,12561,236,78,10},
				{4, 5, 6, 7,8,9,1,2,3},
				{7, 8, 9, 10,11,4,51,6,9138},
				{22,23,24,25,26,12561,236,78,10}
			};
int x[m] = {1,2,3,4,5,6,7,8,9};
int y[m]; // vetor resultado

void *Pth_mat_vect(void* rank){
    long my_rank = (long) rank;
    int i, j;
    int local_m = m / thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank + 1) * local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++)
	{
        y[i] = 0.0;
        for (j = 0; j < n; j++)
        	y[i] += A[i][j] * x[j];
    }
    //printf("Hello from thread %ld of %d\n",my_rank,thread_count);
    return NULL;
}

int main(int argc, char* argv[]) {
	pthread_t threadsss[NUM_T];
	int rc;
    long t;

    thread_count = strtol(argv[1], NULL, 10);

    //criando 3 threads 
	for (t = 0; t <= NUM_T; t++)
	{
		rc = pthread_create(&threadsss[t], NULL, Pth_mat_vect, (void *)t);
		if (rc){printf("ERR0R - ferrou"); exit(-1);}
	}
    //juntando e esperando todos os threads completos
    for (int t = 0; t < NUM_T; t++)
        pthread_join(threadsss[t], NULL);
    
	for (int i = 0; i < m; i++)
		printf("%d\t", y[i]);
	printf("\n");
	pthread_exit(NULL);
}
