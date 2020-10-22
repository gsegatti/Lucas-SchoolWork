#include <stdio.h>
#include <math.h>
#define maxsize 101

//gcc -o ex3 ex3.c -lm para compilar

int main(){
	float vet[maxsize];

	int tam;

	printf("Insira o tamanho da entrada: (Maximo = 100)\n");
	scanf("%i", &tam);

	printf("Insira os elementos do vetor:\n");
	for(int i = 0; i < tam; i++){
		scanf("%f", &vet[i]);
	}

	float media = 0, dp = 0;

	for(int j = 0; j < tam; j++){
		media = media + vet[j];
	}
	media = media/(float)tam;


	//dp = sqrt((SUM((xi-media)^2))/num elementos)
	//sendo xi um elemento do vetor
	//primeiro calcularemos o resultado do somatorio
	float soma = 0, temp;
	for(int j = 0; j < tam; j++){
		temp = (vet[j]-media);
		soma = soma + (temp*temp);
	}
	//dividimos a soma pelo numero de elementos
	//e finalmente tiramos a raiz quadrada
	temp = soma/(float)tam;
	dp = sqrt(temp);

	printf("Media: %.5f, Desvio: %.5f\n", media, dp);
}