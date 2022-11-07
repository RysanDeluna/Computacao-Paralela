# Problema dos Trapézios aplicados à função
---
## Descrição

### Sobre o Problema
Nesta tarefa foi implementado um programa em C que utiliza da biblioteca openMP para paralelizar o cálculo da área de funções.
A função utilizada foi $f(x)=cos(e^{-x})$ que gera o seguinte gráfico:
![image](https://user-images.githubusercontent.com/82891214/200207311-e9c92bb0-7da1-47a4-abe3-fa97fef14903.png)

### Objetivo
O objetivo é comparar as distintas técnicas de acesso e controle à região crítica, tanto quanto no tempo de execução, quanto em precisão.
Na parte 1 da atividade, a região crítica é controlada pela construção `#pragma omp critical`, enquanto na parte 2 ela é controlada pelo uso de locks.

---
## Compilação
A compilação foi feita no LearnerLab da AWS utilizando distintos processadores, mas, em todos os casos, a compilação e execução foram feitas da seguinte maneira:
```
$ gcc [codigo_fonte] -o [arq_executavel] -fopenmp -lm
$ ./[arq_executavel]
```

## Resultados
*Devido à alguns problemas no ambiente AWS, não foi possível testar as implementações com 4 e 8 processadores*

A precisão em ambas as implementações é semelhante, como é possível ver nas imagens ao fim desta página. 

Executou-se o programa 3 vezes para cada número de processadores e, então, se calculou a média. E, a partir dela, adquirimos o SpeedUp.
Abaixo, seguem-se os tempos de execução (em milisegundos) de acordo com a quantidade de processadores, assim como o SpeedUp.

### Parte 1
| Execução | 1 Processador | 2 Processadores |
| --- | --- | --- |
| 1 | 49 | 35 |
| 2 | 48 | 38 |
| 3 | 47 | 31 |
| Média | 48 | 34,667 |

| Processadores | SpeedUp |
| --- | --- |
| 2 | 1,3846 |

### Parte 2
| Execução | 1 Processador | 2 Processadores |
| --- | --- | --- |
| 1 | 50 | 32 |
| 2 | 48 | 44 |
| 3 | 47 | 30 |
| Média | 48,333 | 35,333 |

| Processadores | SpeedUp |
| --- | --- |
| 2 | 1,367927 |

O próximo passo é criar um gráfico de escalabilidade dos SpeedUp's, pois, conforme dito anteriormente, não foi possível criar instâncias com mais processadores para aquisição de mais dados.

---
## Imagens da execução

### Com 1 processador:

![image](https://user-images.githubusercontent.com/101070455/200198165-4520c365-8824-474b-88f1-e15dc30c2b57.png)
![image](https://user-images.githubusercontent.com/101070455/200198171-0cd31ae1-bc8c-4c5e-8002-46d8a8d2b123.png)

### Com 2 processadores:

![image](https://user-images.githubusercontent.com/74800062/200198207-4955ceb3-b2df-475a-91a3-597c78902c1f.png)
![image](https://user-images.githubusercontent.com/74800062/200198198-92bd5cbf-1d5c-4bae-a8d1-4f9af5bb5011.png)
