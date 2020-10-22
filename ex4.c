#include <stdio.h>
#define maxsize 50

int main(){
	int vet[maxsize];
	int par[maxsize];
	int imp[maxsize];

	int tam;
	printf("Insira o tamanho da entrada: (Maximo = 50)\n");
	scanf("%i", &tam);

	printf("Insira os elementos do vetor:\n");
	for(int i = 0; i < tam; i++){
		scanf("%i", &vet[i]);
	}

	//ordenamos o vetor inteiro de uma vez, evitando repetir a ordenacao
	//para o vetor impar e par separadamente
	//-> se o elemento atual é maior que o próximo
	//		trocamos os elementos de lugar
	//repete-se essa operação até encontrarmos o final do vetor ou um elem maior
	for(int k = 0; k < tam; k++){
		for(int l = k+1; l < tam; l++){
			if(vet[k] > vet[l]){
				int temp = vet[l];
				vet[l] = vet[k];
				vet[k] = temp;
			}
		}
	}

	//separando os elementos, p1 aponta para a ultima posição de par[] e p2 para impar[]
	int p1 = 0, p2 = 0;
	for(int j = 0; j < tam; j++){
		if(vet[j]%2 == 0){ //par
			par[p1] = vet[j];
			p1 = p1+1;
		}
		else{
			imp[p2] = vet[j];
			p2 = p2+1;
		}
	}


	//agora, intercalaremos os elementos enquanto houvermos em ambos vetores
	int j = 0, even = 0, odd = 0;
	for(; even < p1 && odd < p2; j++){
		if(j%2 == 0){
			vet[j] = par[even];
			even = even+1;
		}
		else{
			vet[j] = imp[odd];
			odd = odd+1;
		}
	}

	//agora, ao menos um vetor foi todo utilizado
	//logo, basta checar se em algum vetor restou elementos

	if(even < p1){
		while (even <= p1){
			vet[j] = par[even];
			even = even+1;
			j = j+1;
		}
	}
	if(odd < p2){
		while (odd <= p2){
			vet[j] = imp[odd];
			odd = odd+1;
			j = j+1;
		}
	}


	printf("Os elementos intercalados são:\n");
	for(int k = 0; k < tam; k++){
		printf("%i ", vet[k]);
	}
	printf("\n");

	return 0;
}