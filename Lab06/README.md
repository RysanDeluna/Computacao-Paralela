# Como compilamos o código:
-  A compilação está detalhada e implementada no arquivo <runn.sh>, portanto basta executar utilizando o Bash da seguinte forma: 

```
$ bash runn.sh
```

> Os arquivos fonte .c devem estar na mesma pasta que o _script_

-  Para compilar sem o comando acima, execute as seguintes instruções:

### Versão com PThread:
```
$ gcc -pthread main.c -o paralela
$ ./paralela <numero de threads>
```
### Versão Serial
```
$ gcc main2.c -o serial
$ ./serial
```

---

# Implementação da função `main()`:
- Declara-se um vetor para variáveis do tipo `pthread_t`; 
- Cria-se um número definido de threads para a função `Pth_mat_vect()` utilizando a sub-rotina `pthread_create()` que serão alocadas no vetor `threadsss`;
- Ao fim, utiliza-se a sub-rotina `pthread_join()` para aguardar o fim da execução de cada thread criada e mesclar seus resultados. 

---

# Exemplo de execução: 
### Programa em paralelo:
![image](https://user-images.githubusercontent.com/82891214/190283772-32eacecd-b4a8-4c8e-930f-d84f84ff7e72.png)

### Programa serial:
![image](https://user-images.githubusercontent.com/82891214/190283792-5ce34e06-3996-4946-9ba7-49f4c04d1988.png)
