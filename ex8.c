#include <stdio.h>
#include <stdbool.h>
#define maxcol 32
#define maxlin 13

int main(){
	int cal[maxlin][maxcol];

	//cal representa um calendário onde as linhas sao os meses e as colunas dias
	//meses mais curtos possuem -1 nas celulas, indicando dia n existente
	//os dias validos possuem 1
	/*		1 2 3 4 5 6 7 8 9 10....                        31
		jan
		fev                                                 -1 
		mar
		 .
		 .
		 .
	*/
	//inicializamos a matriz com todos dias validos
	for(int i = 1; i < maxlin; i++){
		for(int j = 1; j < maxcol; j++){
			cal[i][j] = 1;
		}
	}
	//e alteramos as excecoes
	cal[2][31] = -1; cal[2][30] = -1; cal[2][29] = -1; //fevereiro
	cal[4][31] = -1; //abril
	cal[6][31] = -1; //junho
	cal[9][31] = -1; //set
	cal[11][31] = -1; //out


	int dias = 1, soma = 0;
	while(dias != 0){
		printf("\nInforme a quantidade (> 0 ou < 0) de dias a ser subtraida ou acrescida:\n");
		scanf("%d", &dias);

		if(dias == 0)
			break;

		soma = dias;
		int dia = 0, mes = 0, ano = -1;		

		while (ano < 0 || ano > 9999){
			printf("\nInforme o ano desejado:\n");
			scanf("%i", &ano);
		}

		while (mes < 1 || mes > 12){
			printf("\nInforme o mes desejado:\n");
			scanf("%i", &mes);
		}

		bool flag = true;
		while(dia <= 0 || flag){
			printf("\nInforme o dia desejado:\n");
			scanf("%i", &dia);
			if (dia > 0 && dia <= 31){
				if(cal[mes][dia] == -1){
					flag = true;
				}
				else{
					flag = false;
				}
			}
			else{
				flag = true;
			}
		}

		//anos bissextos possuem 1 dia a mais!
		if(((ano%4 == 0) && (ano%100 != 0)) || (ano%400 == 0)){
			cal[2][29] = 1;
		}


		//temos dois casos, soma > 0 ou soma < 0
		//se a soma é maior que 0, andaremos para a direita na matriz
		//caso contrario, andaremos para tras
		//temos de lembrar de pular uma linha quando avançamos/regredirmos 1 mes
		int i = mes, j = dia;
		if(soma > 0)
		{
			while(soma != 0 || cal[i][j] == -1){
				if(cal[i][j] == -1){//dias nao existentes ex: fev 31
					j += 1;
					soma = soma + 1;
				}

				if(j == 31 && i == 12){//troca o ano, mes e dia
					j = 1;
					i = 1;
					ano += 1;
					if(((ano%4 == 0) && (ano%100 != 0)) || (ano%400 == 0)){
						cal[2][29] = 1; //ano bissexto!
					}			
					else{
						cal[2][29] = -1;
					}
				}
				else if(j == 32){ //troca o mes e dia
					j = 1;
					i = i+1;
				}
				else{//troca o dia
					j = j+1;
				}
				if(j == 32){//caso ultima troca do 'else' extoure
					j = 1;
					i = i+1;
				}
				if(i > 12){
					i = 1;
					j = 1;
					ano += 1;
				}	
				soma = soma -1;
			}
		}
		else{
			while(soma != 0 || cal[i][j] == -1){
				while(cal[i][j]==-1){
					j -= 1;
				}
				if(soma<0){
					if(j == 1 && i == 1){//troca o ano, mes e dia
						j = 31;
						i = 12;
						ano -= 1;
						if(((ano%4 == 0) && (ano%100 != 0)) || (ano%400 == 0)){
							cal[2][29] = 1; //ano bissexto!
						}			
						else{
							cal[2][29] = -1;
						}
					}
					else if(j == 0){ //troca o mes e dia
						i = i-1;
						j = 31;
					}
					else{
						j = j-1;
					}
					if(j == 0){
						j = 31;
						i = i-1;
					}
					if(i == 0){
						i = 12;
						j = 31;
					ano -= 1;
					}
					while(cal[i][j]==-1){
						j -= 1;
					}
					soma += 1;
				}
				else
					break;	
			}
		}

		printf("\nResultado final:\n");
		if(j < 10){
			printf("0%i/", j);
		}
		else{
			printf("%i/", j);
		}
		if(i < 10){
			printf("0%i/", i);
		}
		else{
			printf("%i/", i);
		}
		if(ano < 10){
			printf("000%i\n", ano);
		}
		else if(ano < 100 && ano > 9){
			printf("00%i\n", ano);
		}
		else if(ano > 99 && ano < 1000){
			printf("0%i\n", ano);
		}
		else{
			printf("%i\n", ano);
		}
	}	
	return 0;
}