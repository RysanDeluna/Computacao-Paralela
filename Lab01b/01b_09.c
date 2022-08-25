// 9 Crie uma função capaz de substituir todos os números negativos de uma matriz por seu módulo.
#include <stdio.h>
#define L 4
#define C 4

void imprime_matriz(int M[L][C]);
void modulo(int M[L][C]);

void imprime_matriz(int M[L][C])
{
    for(int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
}

void modulo(int M[L][C])
{
    for(int i = 0; i < L; i++)
        for (int j = 0; j < C; j++)
            if (M[i][j] < 0) M[i][j] *= -1;
}

int main()
{
    int m[L][C] = {{1,-2,3,10},{4,5,-6,90},{7,8,9,-30},{-7,8,-9,30}};
    modulo(m);
    imprime_matriz(m);

    return 0;
}
