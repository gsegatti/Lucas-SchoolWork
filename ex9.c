#include <stdio.h>
#define maxsize 1000

int main(){
	//assumindo um conjunto discreto
	//caso contrario, mude para float
	int vet[maxsize];

	int tam;

	printf("Insira o tamanho da entrada: (Maximo = 1000)\n");
	scanf("%i", &tam);

	printf("Insira os elementos do vetor:\n");
	for(int i = 0; i < tam; i++){
		scanf("%i", &vet[i]);
	}


	//Para acharmos a moda, precisamos achar o elemento que ocorre o maior numero
	//de vezes no vetor.
	
	//logo, precisamos de uma variavel fixada em um elemento, enquanto outra
	//percorre o vetor e conta quantas vezes este numero ocorre

	//como o enunciado pede por um algoritmo que retorne A moda de um vetor
	//caso encontremos um vetor bimodal, trimodal ou multimodal, basta retornar
	//um dos elementos mais frequentes


	int count = 0, max = -1, moda = -1;
	for(int i = 0; i < tam; i++){
		count = 0;
		for(int j = i; j < tam; j++){
			if(vet[i] == vet[j]){
				count = count + 1;
			}
		}
		if(count > max){
			moda = vet[i];
			max = count;
		}
	}
	if(max == -1){
		printf("O vetor nao possui moda.\n");
	}
	else if(max == 1){
		printf("O vetor nao possui moda, visto que nenhum elemento ocorre mais de uma vez.\n");
	}
	else{
		printf("A moda do vetor é: %i, ocorrendo %i vezes.\n", moda, max);
	}
}