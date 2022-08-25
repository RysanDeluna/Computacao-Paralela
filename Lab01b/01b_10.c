#include <stdio.h>

void multi(int matriz[][3]){
	int l, c, m;
	
	printf("digite a linha que deseja multiplicar: ");
    scanf("%d", &l);
    
    printf("digite a coluna que deseja multiplicar: ");
    scanf("%d", &c);
    
    printf("digite um valor para multiplicar:");
    scanf("%d", &m);
    
    for (int i = 0; i < 3; i++)
	{
		matriz[l][i] *= m;
        matriz[i][c] *= m;
	}
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d\t", matriz[i][j]);
        printf("\n");
    }
}

int main(){
	
	int M[3][3];
	printf("complete a matriz: ");
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
    
    multi(M);
}
