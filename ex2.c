#include <stdio.h>
#include <stdbool.h>
#define maxsize 1000

int main(){
	//1000 +1 para incluir o número 1000 no calculo, visto que o primeiro index == 0
	bool primo[maxsize+1];


	int tam;

	printf("Ate qual numero deseja saber a sequencia de numeros primos? (Maximo = 1000)\n");
	scanf("%i", &tam);

	//inicialmente consideramos todos os números como sendo primos
	for(int i = 0; i <= tam; i++){
		primo[i] = true;
	}

	//O e 1 multiplicados por si mesmos não geram outros números logo os pulamos
	//de 2 em diante, se o número atual é primo
	//	escolhemos seu próximo multiplo e marcamos como não primo
	//repete-se até seu múltiplo ultrapassar 1000
	for(int i = 2; i <= tam; i++){
		if(primo[i]){
			for(int j = i*i; j <= maxsize; j+=i){
				primo[j] = false;
			}
		}
	}

	
	printf("Os numeros primos menores ou iguais a %i:\n", tam);
	for(int i = 2; i <= tam; i++){
		if(primo[i]){
			printf("%i ", i);
		}
	}
	printf("\n");

	return 0;
}