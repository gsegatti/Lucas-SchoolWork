#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define size_mes 30
#define size_horas 24
#define max_consumo 100
#define max_index 0.15

int main(){
	/*
		tabela onde cada dia do mes é uma linha e as horas sao as 24 colunas
		guardando o consumo naquele determinado momento
				0hrs	1hr		2hrs...
		dia 1
		dia 2
		 .
		 .

	*/
	srand(time(NULL));
	float table[size_mes][size_horas];
	float total = 0;


	//primeiro temos de distribuir o consumo pelas horas e dias da tabela
	//levando em conta o limite de 100 unidades
	//temos 720 "casas" e, logo, aproximadamente 0.14 unidades por hora podem ser consumidas

	for(int i = 0; i < size_mes; i++){
		for(int j = 0; j < size_horas; j++){
			table[i][j] = (((float)rand()/RAND_MAX)*0.15);
			total += table[i][j];
		}
	}

	while(1){
		printf("\n\n_________MENU_________\n\n");

		int opcao = 0;

		printf("0 - Sair.\n");
		printf("1 - Total consumido durante o mes:\n");
		printf("2 - Total consumido durante finais de semana:\n");
		printf("3 - Dia de maior consumo no mes:\n");
		printf("4 - Hora com maior consumo medio no mes:\n");
		printf("5 - Total a ser pago:\n\n");

		while(opcao < 1 || opcao > 5){
			scanf("%i", &opcao);
			if(opcao == 0)
				return 0;
			if(opcao >= 1 && opcao <= 5)
				break;
			else{
				printf("Escolha invalida. Tente novamente:\n");
			}
		}


		if(opcao == 1){
			printf("\nO total de unidades consumidas durante o mes é: %.2f.\n", total);
		}
		else if(opcao == 2){
			float total_fds = 0;
			for(int i = 5; i < size_mes; i=i+7){
				
				for(int j = 0; j < size_horas; j++){
					//						sabado        domingo
					total_fds = total_fds + table[i][j] + table[i+1][j];
				}
			}
			printf("\nO total de unidades consumidas durante os finais de semana foi: %.2f.\n", total_fds);		
		}
		else if(opcao == 3){
			float temp, max = -1;
			int dia = -1;

			for(int i = 0; i < size_mes; i++){
				temp = 0;
				for(int j = 0; j < size_horas; j++){
					temp = temp + table[i][j];
				}
				if(temp > max){
					max = temp;
					dia = i;
				}
			}

			printf("\nO dia que mais contribuiu para a conta mensal é: %i.\n", dia);
		}
		else if(opcao == 4){
			float max_media = -1, media;
			int hr;
			for(int i = 0; i < size_horas; i++){
				media = 0;
				for(int j = 0; j < size_mes; j++){
					media = media + table[j][i];
				}
				media = media/(float)size_mes;

				if(media > max_media){
					max_media = media;
					hr = i;
				}
			}

			printf("\nA hora de maior consumo médio foi: %i.\n", hr);
		}
		else{//opcao = 5
			float preco_total = 0;
			int sab = 5, dom = 6;

			for(int i = 0; i < size_mes; i++){
				for(int j = 0; j < size_horas; j++){
					if(j < 5){
						preco_total = preco_total + (table[i][j]*8.5);
					}
					else if(j > 17 ){
						preco_total = preco_total + (table[i][j]*15.0);
					}
					else if(i == sab){
						preco_total = preco_total + (table[i][j]*15.0);
						sab = sab+7; //ocorrencia do proximo sabado na table
					}
					else if(i == dom){
						preco_total = preco_total + (table[i][j]*15.0);
						dom = dom+7; //ocorrencia do proximo sabado na table
					}
					else{
						preco_total = preco_total + (table[i][j]*10.0);
					}
				}
			}
			printf("\nO valor mensal a ser pago: %.2f reais.\n", preco_total);
		}
	}
	return 0;
}