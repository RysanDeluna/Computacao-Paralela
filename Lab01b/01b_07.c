#include <stdio.h>
#include <string.h>

/*7. Faça um programa que crie um vetor de pessoas. 
Os dados de uma pessoa devem ser armazenados em um variavel do tipo struct. 
O programa deve permitir que o usuário digite o nome de 3 pessoas e a seguir imprimi os dados de todas as pessoas. 
A struct deve armazenar os dados de idade, peso e altura.*/

typedef struct{
	int idade;
	float peso;
	float alt;
}pessoa;

pessoa setPessoa(int age, float weight, float height){
	
	pessoa p;
	p.idade = age;
	p.peso = weight;
	p.alt = height;
	
	return p;
}

void imprimirPessoa(pessoa p) 
{	
	printf("Idade: %d  Peso: %f Altura: %f\n", p.idade, p.peso, p.alt);
}

int main(){
	pessoa nomes[3];
	float altura, peso;
	int idade;
	
	for (int i = 0; i < 3; i++){
		printf("digite nome da %d pessoa:", i+1);
		scanf("%s", &nomes[i]);
		printf("%s\n", nomes[i]);
		
		
	}
	
	for (int i = 0; i < 3; i++){
		printf("digite idade, peso e altura: ");
		scanf("%d %f %f", &idade, &peso, &altura);
		nomes[i] = setPessoa(idade, peso, altura);
		imprimirPessoa(nomes[i]);
	}
	
	
	
	
	
}
