#include <stdio.h>
long long int 	fat(int n);
long double 	taylor(int n);

long long int fat(int n) 
{
	long long int result = 1;
	while (n != 0) 
	{
		result *= n;
		n--;
	}
	return result;
}

long double taylor (int n)
{
    double soma = 0.0;
    for (int i = 1; i < n; i++)
		soma += 1 / (double) fat(i);
	return soma;
}

int main(int argc, char *argv[]) 
{
	printf("%.33Lf\n", taylor(20));
	return 0;
}
