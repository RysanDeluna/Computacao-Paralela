// 13. Faça um rotina que remova um caracter de uma string do tipo char Str[100], dada a posição do caracter.
#include <stdio.h>
#define TAM 100

int removeC(char str[TAM], int pos);

int main()
{
    char str[TAM] = "AEJCrmriPxpORLIYuSuqLXQkqLroFimHDMwMsewTbVrAtFhaznCodibnXCaIKpPLxeZefMJTrUNniIqsQtlFHDQnhZyCvLPGyzUI";
    int num;
    scanf("%d", &num);
    removeC(str, num);
    printf("%s", str);
    return 0;
}

int removeC(char str[TAM], int pos)
{
    for (int i = 0; i < TAM; i++)
        if (i == pos)
        {
            for(int j = i; j < TAM; j++)
                str[j] = str[j + 1];
            return (0);
        }
}
