#include <stdio.h>

int main()
{
    int M[3][3], l, m, c;

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
	printf("digite a linha que deseja multiplicar: ");
    scanf("%d", &l);
    
    printf("digite a coluna que deseja multiplicar: ");
    scanf("%d", &c);
    
    printf("digite um valor para multiplicar:");
    scanf("%d", &m);
    
    for (int i = 0; i < 3; i++)
	{
		M[l][i] *= m;
        M[i][c] *= m;
	}
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
    return 0;
}
