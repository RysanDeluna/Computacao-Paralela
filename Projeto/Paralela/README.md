# Versão Paralela do Cálculo da Constante de Euler
---
## Sobre o Código
O código foi escrito na **linguagem C** e compilado com **GCC** no ambiente AWS utilizando o processador t3.micro de 2 núcleos.

Nele há duas funções, `long long fat(int n)` e `void *taylor(void* rank)`. A primeira é responsável pelo cálculo do fatorial e foi implementada de forma dinâmica utilizando do vetor `fats` de tamanho fixo mirado no objetivo final do projeto. A segunda se encarrega de realizar o cálculo de Euler com somas sucessivas de acordo com a thread que está sendo executada.

Ressalta-se o uso do *mutex* para impedir que as duas alterem a região crítica ao mesmo tempo e cause problemas ao resultado final. 

---
## Saída
![image](https://user-images.githubusercontent.com/74800062/196840840-dba3009e-42eb-4808-9351-29e7ae87e937.png)

---
## Problemas encontrados

1. Dificuldade de rodar acima de 50 iteração
2. Há um core dumped em relação ao tamanho do vetor por ser valor alto, em que armazena o valor do fatorial
3. Máximo de fatorial certo é 20.
4. Dificuldade em conectar em AWS.

---

## SpeedUp

Sp = Tempo de um processador / Tempo de p processadores = 0,001 / 0,001 = 1
