#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define	BUF_SIZE	100

// protótipo dos processos 42080223
void	pares(int j, int sharedMem[]);
void	impares(int j, int sharedMem[]);

int main(void)
{
	// configurando memória compartilhada
	key_t	chave = 666;	
	int		shm_id;
	int 	*shmptr;
	
	shm_id = shmget(chave, 4*sizeof(int), IPC_CREAT | 0666);
	shmptr = (int *) shmat(shm_id, NULL, 0);
	
	shmptr[0] = 1;
	shmptr[1] = 1;
	
	//
	pid_t	pid;
	int		j;
	char	buf[BUF_SIZE];
	
	sprintf(buf, "Digite o número: "); 
	write(1, buf, strlen(buf));
	
	scanf("%d", &j);
	
	pid = fork();
	if (pid == 0)		// FILHO
	{
		pares(j, shmptr);
		sprintf(buf, "O fatorial deste número é: %d (rodado pelo processo %d)\n", shmptr[1] * shmptr[0], pid = getpid());
		write(1, buf, strlen(buf));	
	}
	else if (pid > 0)	// PAI
	{
		impares(j, shmptr);	
	}		
	return 0;
}
														
// função responsável pelo cálculo dos pares
void pares(int j, int sharedMem[])
{
	if (j % 2 == 0)
		for (; j > 1; j -= 2) 
			sharedMem[0] *= j;
	else
	{
		j--;
		for (; j > 1; j -= 2)
			sharedMem[0] *= j;
	}
}

// função responsável pelo cálculo dos ímpares
void impares(int j, int sharedMem[])
{
	if (j % 2 != 0)
		for (; j > 1; j -= 2) 
			sharedMem[0] *= j;
	else
	{
		j--;
		for (; j > 1; j -= 2)
			sharedMem[0] *= j;
	}
}
 
