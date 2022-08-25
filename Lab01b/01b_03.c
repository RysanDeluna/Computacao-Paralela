#include <stdio.h>

int main(){
	int num, v, h;
	
	do {
		printf("digite um numero impar: ");
		scanf("%d", &num); 
	} while (num%2 == 0);
	
	for (v = 1; v <= (num/2) + 1; v++)
	{
		for (h = 1; h <= (num - v) + 1 ; h++)
		{
			if (h >= v)
				printf("%d", h);
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
