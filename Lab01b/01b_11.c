// 11. Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma matriz.
// O resultado deve ser colocado na linha L2. Faça o mesmo com a multiplicação.
#include <stdio.h>
#define TAM_MAX 3

void soma(int M[TAM_MAX][TAM_MAX]);
void mult(int M[TAM_MAX][TAM_MAX]);
void imprime_matriz(int M[TAM_MAX][TAM_MAX]);

void imprime_matriz(int M[TAM_MAX][TAM_MAX])
{
    for(int i = 0; i < TAM_MAX; i++)
    {
        for (int j = 0; j < TAM_MAX; j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
}

void soma(int M[TAM_MAX][TAM_MAX])
{
    for (int j = 0; j < TAM_MAX; j++)
        M[1][j] += M[0][j];
}

void mult(int M[TAM_MAX][TAM_MAX])
{
    for (int j = 0; j < TAM_MAX; j++)
        M[1][j] *= M[0][j];    
}

int main()
{
    int m[TAM_MAX][TAM_MAX] = {{1,2,3},{1,2,4},{9,93,2}};

    imprime_matriz(m); printf("\n");
    soma(m);
    imprime_matriz(m); printf("\n");
    mult(m);
    imprime_matriz(m); printf("\n");
    return 0;
}

