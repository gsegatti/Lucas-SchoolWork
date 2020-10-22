#include <stdio.h>
#define maxsize 51
#define INT_MIN -2147483647

int main(){
	float vet[maxsize];

	int tam;
	printf("Insira o tamanho da entrada: (Maximo = 50)\n");
	scanf("%i", &tam);

	printf("Insira os elementos do vetor:\n");
	for(int i = 0; i < tam; i++){
		scanf("%f", &vet[i]);
	}

	//encontrando o maximo do vetor
	float max = INT_MIN;
	for(int j = 0; j < tam; j++){
		if (vet[j] > max){
			max = vet[j];
		}
	}

	printf("\n");
	for(int j = 0; j < tam; j++){
		vet[j] = vet[j]/(float)max;
		printf("%.2f ", vet[j]);
	}

	printf("\n");

	return 0;
}