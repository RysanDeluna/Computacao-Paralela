# Explicação do código

Desenvolvemos o programa com a **linguagem C** e compilamos com **GCC** no ambiente AWS utilizando o processador t3.micro de 2 núcleos. Além disso, utilizamos processador t2.micro de 1 núcleo para comparar o tempo de execução entre eles.

Nele há duas funções, `unsigned long long int fat(int n)` e `void taylor(int n, long double *global)`. A primeira é responsável em calcular o fatorial e na segunda, realiza o cálculo de Euler com somas sucessivas de acordo com a thread que está sendo executada.

Além disso, utilizamos `OpenMP` para criar threads e para impedir o acesso a região crítica, implementamos `#pragma omp critical`.


# Compilação

Para compilar: 
> gcc [nome do arquivo] -o [arquivo executável] -fopenmp -lm

Para rodar, e para saber o tempo de execução basta adicionar `time` antes. 
> time ./[arquivo executável] [número de threads]

# Resultado

Devido à alguns problemas no ambiente AWS, não foi possível testar as implementações com 4 e 8 processadores

### 1 Processador
| Execução | Nº de Threads | Tempo | Número de n |
| --- | --- | --- | --- | 
| 1 | 15 | 353s | 10.000 |
| 2 | 15 | 2s | 50 |
| 3 | 15 | 6s | 1000 |
| 4 | 20 | 6s | 1000 |
| 5 | 50 | 8s | 1000 |
| Média | |6.667s | 1000 |


### 2 Processador
| Execução | Nº de Threads | Tempo | Número de n |
| --- | --- | --- | --- | 
| 1 | 15 | 210s | 10.000 |
| 2 | 15 | 2s | 50 |
| 3 | 15 | 4s | 1000 |
| 4 | 20 | 5s | 1000 |
| 5 | 50 | 7s | 1000 |
| Média | |5.333s | 1000 |

## GRÁFICO



# Imagens de execução

### 1 Processador
![image](https://user-images.githubusercontent.com/74800062/200965676-9c9d778d-56a6-491c-b502-207a7d7bc584.png)
![image](https://user-images.githubusercontent.com/74800062/200965681-81b5c272-9e46-41cf-92b5-07c34eecc623.png)


### 2 Processador
![image](https://user-images.githubusercontent.com/74800062/200966465-76cd2e61-3659-47b0-a5d5-5cf697a53beb.png)
![image](https://user-images.githubusercontent.com/74800062/200965773-d89f6a64-f138-4565-85f0-edba046c9673.png)
![image](https://user-images.githubusercontent.com/74800062/200965814-c38ae34e-11b4-466b-b569-9318fc2b84f1.png)

