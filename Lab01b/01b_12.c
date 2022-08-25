// 12. Faça uma função que retorne a posição de um dado caracter dentro de uma string.
#include <stdio.h>
int pos_char(char str[], char c);

int pos_char(char str[], char c)
{
    int i = -1;
    while(str[i++] != '\0')
        if (str[i] == c) return i + 1;
    return -1;
}

int main()
{
    char str[] = "ablublé", c;

    printf("Digite o caractere procurado: ");
    scanf("%c", &c);
    printf("\n");
    printf("Tal caractere está na posicao: %d" ,pos_char(str, c));
    return 0;
}
