#include <stdio.h>
#define maxsize 3

int main(){
	float mat[maxsize][maxsize];

	int dim;
	printf("Insira a dimensao da matriz: (Maximo = 3)\n");
	scanf("%i", &dim);


	printf("Insira os elementos da matriz:\n");
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			scanf("%f", &mat[i][j]);
		}
	}


	if(dim == 0){
		printf("Determinante = 0.\n");
	}
	else if(dim == 1){
		printf("Determinante = %.2f.\n", mat[0][0]);
	}
	else if(dim == 2){
		printf("Determinante = %.2f.\n", (mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]));
	}
	else{
		/*
		Para N=3 repetimos as duas primeiras colunas ao lado da matriz:
		[1,2,3] [1, 2]
		[4,5,6] [4, 5]
		[7,8,9] [7, 8]

		e multiplicamos as novas diagonais formadas para termos os cofatores:
		3*4*8; 2*6*7; 1*5*9
		depois fazemos no sentido inverso e o determinante é a diferenca das somas!
		*/

		//calculo dos cofatores no primeiro e segundo sentido de multiplicacoes
		float ida[maxsize], volta[maxsize], temp = 1;


		ida[0] = mat[0][2]*mat[1][0]*mat[2][1];

		for(int i = 0; i < maxsize; i++){
			for(int j = 1; j < maxsize; j++){
				temp = temp * mat[i][j];
				i = i+1;
			}
		}
		ida[1] = temp*mat[2][0];

		ida[2] = 1;
		for(int i = 0; i < maxsize; i++){
			for(int j = 0; j < maxsize; j++){
				ida[2] = ida[2] * mat[i][j];
				i = i+1;
			}
		}

		//ida[0]+ida[1]+ida[2] sao as diagonais em um sentido
		//resta calcular volta[n] para chegar ao resultado
		volta[0] = 1;
		for(int i = 0; i < maxsize; i++){
			for(int j = maxsize-1; j > -1; j--){
				volta[0] = volta[0]*mat[i][j];
				i = i+1;
			}
		}

		temp = 1;
		for(int i = 1; i < maxsize; i++){
			for(int j = maxsize-1; j > 0	; j--){
				temp = temp*mat[i][j];
				i = i+1;
			}
		}
		volta[1] = temp*mat[0][0];

		volta[2] = mat[2][2]*mat[1][0]*mat[0][1];

		//agora basta subtrairmos as somas: DET = SUM(IDA)-SUM(VOLTA)

		float res = 0;
		for(int i = 0; i < maxsize; i++){
			res = res + ida[i] - volta[i];
		}
		printf("\n");


		printf("Determinante = %.2f\n", res);
		
	}
	return 0;
}