#include <stdio.h>

int main(){
	
	 int M[3][3], M2[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &M[i][j]);
	printf("\n");
	
	for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			M2[i][j] = M[j][i];
		printf("\n");
	
	for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", M2[i][j]);
        printf("\n");
    }
}
