#include <stdio.h>
#define maxsize 200

int main(){
	float mat[maxsize][maxsize];

	int dim;
	printf("Insira a dimensao da matriz: (Maximo = 200)\n");
	scanf("%i", &dim);


	printf("Insira os elementos da matriz:\n");
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			scanf("%f", &mat[i][j]);
		}
	}

	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			if(i == j){
				if(mat[i][j] != 1){
					printf("A matriz nao eh identidade!\n");
					return 0;
				}
			}
			else{
				if(mat[i][j] != 0){
					printf("A matriz nao eh identidade!\n");
					return 0;
				}
			}
		}
	}

	printf("A matriz eh identidade!\n");
	return 0;

}