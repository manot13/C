#include<stdio.h>
#include<stdlib.h>
#define N 12

void ler(int mtx[N][N]){
	FILE* arquivo;
	arquivo = fopen("numeros.txt", "r");
	if(arquivo==NULL){
		printf("Problemas na abertura do arquivo!\n");
	}
	else{
		int lin, col;
		for(lin=0; lin<N; lin++){
			for(col=0; col<N; col++){
				fread(&mtx[lin][col], sizeof(int), 1, arquivo);
			}
		}	
	}
	fclose(arquivo);
}

void grava(){
	int mtx[N][N]={
		{135, 177, 121, 111, 102, 209, 328, 752, 124, 333, 402, 509},
		{902, 107, 208, 304, 90, 95, 39, 108, 222, 369, 124, 503},
		{308, 92, 59, 40, 509, 18, 29, 339, 185, 1, 5, 35},
		{307, 88, 147, 258, 869, 566, 788, 33, 41, 25, 589, 133},
		{875, 88, 967, 136, 151, 55, 33, 8, 17, 39, 321, 123},
		{208, 120, 774, 36, 150, 104, 22, 80, 71, 93, 405, 315},
		{104, 512, 233, 522, 140, 940, 715, 18, 82, 51, 17, 32},
		{25, 44, 57, 501, 270, 171, 244, 218, 521, 501, 18, 22},
		{99, 17, 905, 54, 193, 281, 92, 83, 701, 110, 15, 290},
		{512, 163, 174, 285, 196, 160, 810, 122, 114, 512, 45, 81},
		{10, 21, 32, 43, 54, 65, 76, 87, 98, 109, 35, 79},
		{309, 16, 17, 28, 19, 10, 10, 12, 14, 12, 415, 181}
	};
	
	FILE* arquivo;
	arquivo = fopen("numeros.txt", "w");
	if(arquivo==NULL){
		printf("Problemas na abertura do arquivo!\n");
	}
	else{
		int lin, col;
		
		for(lin=0; lin<N; lin++){
			for(col=0; col<N; col++){
				fwrite(&mtx[lin][col], sizeof(int), 1, arquivo);
			}
		}	
	}
	fclose(arquivo);
}

main(){
	int matriz[N][N];

	grava();
	ler(matriz);
	
	int lin, col;
	
	for(lin=0; lin<N; lin++){
		for(col=0; col<N; col++){
			if(((col<=lin && col+lin<=11) || (lin+col>=11 && lin<=col))){
				matriz[lin][col]=0;
			}
		}
	}
	
	for(lin=0; lin<N; lin++){
		for(col=0; col<N; col++){
			printf("%5d", matriz[lin][col]);	
		}
		printf("\n");
	}
	
	getchar();
}
