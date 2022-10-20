# Versão Paralela do Cálculo da Constante de Euler
---
## Sobre o Código
O código foi escrito na **linguagem C** e compilado com **GCC** no ambiente AWS.

Nele há duas funções, `long long fat(int n)` e `void *taylor(void* rank)`. A primeira é responsável pelo cálculo do fatorial e foi implementada de forma dinâmica utilizando do vetor `fats` de tamanho fixo mirado no objetivo final do projeto. A segunda se encarrega de realizar o cálculo de Euler com somas sucessivas de acordo com a thread que está sendo executada.

Ressalta-se o uso do *mutex* para impedir que as duas alterem a região crítica ao mesmo tempo e cause problemas ao resultado final. 

---
## Saída

---
## Problemas encontrados

---
