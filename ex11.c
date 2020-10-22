#include <stdio.h>
#define maxname 28
#define maxdata 10
#define maxsize 100000

typedef struct cliente{
	char nome[maxname];
	int prio, dia, mes, ano;
	float res;
}cliente;


int main(){
	//enunciado nao especificou limite
	cliente clientes[maxsize];

	int tam;

	printf("Insira a quantidade de clientes: \n");
	scanf("%i", &tam);

	for(int i = 0; i < tam; i++){
		printf("\nInsira a prioridade do novo cliente:\n");
		scanf("%i", &clientes[i].prio);

		//convertemos as prioridades maiores que 3 para o maximo aceito
		if(clientes[i].prio > 3){
			clientes[i].prio = 3;
		}

		if(clientes[i].prio >= 2){
			printf("\nInforme o primeiro nome:");
			scanf(" %[^\n]s", clientes[i].nome);
			printf("\nDia de nascimento:\n");
			scanf("%i", &clientes[i].dia);
			printf("\nMes de nascimento:\n");
			scanf("%i", &clientes[i].mes);
			printf("\nAno de nascimento:\n");
			scanf("%i", &clientes[i].ano);
			printf("\nValor da reserva:\n");
			scanf("%f", &clientes[i].res);
		}
		else{
			printf("\nInforme o primeiro nome:");
			scanf(" %[^\n]s", clientes[i].nome);
			printf("\nDia de nascimento:\n");
			scanf("%i", &clientes[i].dia);
			printf("\nMes de nascimento:\n");
			scanf("%i", &clientes[i].mes);
			printf("\nAno de nascimento:\n");
			scanf("%i", &clientes[i].ano);
			clientes[i].res = -1;
		}

		verificarnome:
		for(int j = 0; j < maxname; j++){
			if(clientes[i].nome[j] == ' '){
			//espaco
				for(int k = 0; k < maxname; k++){
					clientes[i].nome[k] = 0;
				}
				printf("\nInforme APENAS o primeiro nome do cliente:\n");
				scanf(" %[^\n]s", clientes[i].nome);
				goto verificarnome;
			}
		}
	}

	//ordenamos os clientes por prioridade
	for(int k = 0; k < tam; k++){
		for(int j = k+1; j < tam; j++){
			if(clientes[k].prio > clientes[j].prio){
				cliente temp = clientes[j];
				clientes[j] = clientes[k];
				clientes[k] = temp;
			}
		}
	}

	float total = 0;
	printf("\nClientes com prioridade >= 2:\n");
	for(int i = tam-1; i > -1; i--){
		if(clientes[i].prio < 2){
			break;
		}
		total = total + clientes[i].res;
		printf("\nNome: %s\n", clientes[i].nome);

		printf("Proximo aniversario: ");
		if(clientes[i].dia < 10 && clientes[i].dia > 0){
			printf("0%i/", clientes[i].dia);
		}
		else{
			printf("%i/", clientes[i].dia);
		}
		if(clientes[i].mes < 10 && clientes[i].mes > 0){
			printf("0%i\n", clientes[i].mes);
		}
		else{
			printf("%i\n", clientes[i].mes);
		}

		printf("Reserva: %.2f\n", clientes[i].res);
	}

	printf("\nReservas Totais: %.2f\n", total);
	return 0;
}
