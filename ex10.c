#include <stdio.h>
#define maxsize 50

typedef struct item
{
	float preco, quant;
}item;

int main(){
	item itens[maxsize];

	int tam;

	printf("Insira o tamanho da entrada: (Maximo = 50)\n");
	scanf("%i", &tam);

	printf("Insira o preco por kg e quantidade (em kgs) de cada item comprado:\n");
	for(int i = 0; i < tam; i++){
		scanf("%f %f", &itens[i].preco, &itens[i].quant);
	}


	float total = 0;
	for(int i = 0; i < tam; i++){
		total = total + (itens[i].preco*itens[i].quant);
	}

	printf("O custo total da compra foi: %.2f.\n", total);
}