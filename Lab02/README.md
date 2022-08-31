
# Como compilamos o código:
-  utilizamos o comando `gcc <nome do arquivo>` no terminal do SO Linux

# Modificação:
- no nosso código usamos o comando `fork()` para processamento paralelo, o qual cria 1 processo chamado filho a partir do já existente que passa a ser chamado de pai.
- Vale ressaltar que o processo filho e pai ocupam lugares diferentes da memória e portanto, as variáveis independem uma das outras. Isto implica da necessidade de criar uma memória compartilhada que irá permitir que os processos compartilhem informações.
- Para criar memória compartilhada precisa-se da chamada do sistema `shmget()` e posteriormente viculá-la pela chamada `shmat()`. 
- Com esses conceitos o código foi desenvolvido.
- **OBS**: adiciona-se as bibliotecas `unistd.h`, `sys/types.h`, `sys/ipc.h`, `sys/shm.h`. Pois a primeira lida com a criação de processos e chamadas do sistema UNIX, enquanto as últimas nos permite criar a memória compartilhada e controlar as variáveis relativas à ela e aos processos.
