# Como compilamos o código:
-  A compilação está detalhada e implementada no arquivo <runn.sh>, portanto basta executar utilizando o Bash da seguinte forma: 

```
$ bash runn.sh
```

> Os arquivos fonte .c devem estar na mesma pasta que o _script_

-  Para compilar sem o comando acima, execute as seguintes instruções:

### Versão com PThread:
```
$ gcc -g -Wall -o main main.c -lpthread
$ ./main <numero de threads> <quantidade de digitos>
```
---

# Implementação da função `main()`:
- Declara-se um vetor para variáveis do tipo `pthread_t`; 
- Cria-se um número definido de threads para a função `Thread_sum` utilizando a sub-rotina `pthread_create()` que serão alocadas no vetor `threadsss`;
- Além disso, utiliza-se `mutex` para evitar que a região crítica seja acessada ao mesmo tempo por diferentes threads;
- Ao fim, utiliza-se a sub-rotina `pthread_join()` para aguardar o fim da execução de cada thread criada e mesclar seus resultados. 


---

# Exemplo de execução: 
### Programa em paralelo:
![image](https://user-images.githubusercontent.com/74800062/191617118-72472c91-b347-4e2c-9e41-c7d6b9786ee4.png)

 
