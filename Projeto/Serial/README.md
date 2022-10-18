# Versão Serial do Cálculo da Constante de Euler
---

## Sobre o Código
O código foi escrito na **linguagem C** e compilado utilizando o **GCC** no ambiente AWS.

Nele há duas funções, `long long int fat(int i)` e `long double taylor (int n)`, cujos tipos de retorno buscam a melhor precisão dos resultados obtidos. A função `fat` calcula o fatorial de um número tendo como limite o parâmetro 20 na instância do tipo t2.micro na AWS. Na função `taylor` é feito o cálculo da série em si a partir de um determinado número de iterações, o qual tem limite 20 por depender do resultado de `fat`.

Desta forma, o resultado mais preciso obtido possui apenas 15 casas decimais corretas no tempo de 0.001 segundo.

---
## Saída

Abaixo está o procedimento de como compilar e a saída no terminal de AWS:
![image](https://user-images.githubusercontent.com/82891214/196532243-4568ef41-564c-4f14-a59f-8a4a81547ba7.png)

## Maiores problemas

1. Limitações acerca da estrutura de dados em C
2. Como definir um laço infinito que leve ao maior limite

## Possível resolução

2. Definir um limitador no tempo de execução.
