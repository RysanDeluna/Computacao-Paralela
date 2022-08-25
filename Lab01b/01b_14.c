// 14. Faça um rotina que insira um caracter em uma string do tipo char Str[100], dada a posição do caracter.
#include <stdio.h>
#define TAM 100
#define charac 'x'

int insC(char str[TAM], int pos);

int main()
{
    char str[TAM] = "AEJC";
    int num;
    printf("%s\n", str);
    scanf("%d", &num);
    insC(str, num);
    printf("%s", str);
    return 0;
}

int insC(char str[TAM], int pos)
{
    int j;
    for (int i = 0; i < TAM; i++)
        if (i == pos)
        {
            for(j = TAM - 1; j > i; j--)
                str[j] = str[j - 1];
            str[j--] = charac;
            return (0);
        }
}

