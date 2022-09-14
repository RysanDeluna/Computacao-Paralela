# Como compilamos o código:
-  A compilação está detalhada e implementada no arquivo <runn.sh>. Basta executar pelo bash do Linux da seguinte forma:   <center>`bash runn.sh`</center> 
-  Para compilar sem o comando acima, execute as seguintes instruções:<br>
 `gcc -pthread main.c -o paralela` <br> `./paralela <numero de threads>`
 
---

# Modificação:
- Define-se as variáveis globais e cosntantes
- Cria-se threads utilizando uma sub-rotina `pthread_create()` com os parâmetros que aloca memória, NULL, nome da rotina e argumento da rotina;   
- Também se utiliza sub-rotina `join` para juntar e esperar todos os threads prontos



---

# Exemplo de execução: 
### programa paralelo:

### programa serial:

Como podemos ver pelas imagens acima, o tempo de execução não teve muita diferença, pois houve dependência nas operações de multiplicação dos valores. 
