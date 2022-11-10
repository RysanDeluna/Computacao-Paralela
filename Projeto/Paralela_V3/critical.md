# Como é feito o controle de acesso à região crítica:
A instrução `#pragma omp critical` impede que as threads acessem o mesmo espaço de memória ao mesmo tempo ou desordenadamente, logo, ela é utilizada para evitir conflitos e erros no resultado final. 

No nosso caso, a instrução impede que o resultado das somas locais sejam incrementados no resultado global, que é a última tarefa realizada por um thread.
