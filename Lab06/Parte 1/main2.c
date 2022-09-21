#include <stdio.h>
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

int main(int argc, char * argv[])
{
	for (int i = 0; i < m; i++)
	{
		y[i] = 0.0;
		for (int j = 0; j < n; j++)
			y[i] += A[i][j] * x[j];
	}

	for (int i = 0; i < m; i++)
		printf("%d\t", y[i]);
	printf("\n");
	return 0;
}
