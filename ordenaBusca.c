#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>

void ordena(int* vet, int tam){
	int k, m;
	int aux;
	for(k=0; k<tam-1; k++){
		for(m=k+1; m<tam; m++){
			if(vet[k]>vet[m]){
				aux=vet[k];
				vet[k]=vet[m];
				vet[m]=aux;
			}
		}
	}
}

int busca3(int* vet, int tam, int elem){
	ordena(vet, tam);
	int ini=0;
	int fim=tam;
	int meio;
	int k=0;
	
	while(ini<=fim){
		++k;
		meio=(ini+fim)/2;
		if(elem<vet[meio]){
			fim=meio-1;
		}else if(elem>vet[meio]){
			ini=meio+1;
		}else if(elem==vet[meio]){
			return meio;
			printf("Interações: %d", k);
		}
	}
	printf("Interações: %d", k);
	return -1;
}

main(){
	setlocale(LC_ALL, "Portuguese");
	int k;
	int vet[11] = {50, 70, 45, 22, 90, 15, 31, 27, 12, 51, 89}; //12, 15, 22, 27, 31, 45, 50, 51, 70, 89, 90;  vetor ordenado
	int resultadoBusca;
	
	
	/*resultadoBusca = busca1(vet, 11, 46);
	
	if(resultadoBusca != -1){
		printf("Busca1: Encontrei na posição = %d\n", resultadoBusca);
	}
	else{
		printf("Busca1: Não encontrei!\n");
	}*/
	
	/*resultadoBusca = busca2(vet, 11, 46);
	
	if(resultadoBusca != -1){
		printf("Busca2: Encontrei na posição = %d\n", resultadoBusca);
	}
	else{
		printf("Busca2: Não encontrei!\n");
	}*/
	
	
	resultadoBusca = busca3(vet, 11, 45);
	/*printf("Digite o vetor que quer encontrar: ");
	scanf("%d", &resultadoBusca);*/
	
	if(resultadoBusca != -1){
		printf("Busca3: Encontrei na posição = %d\n", resultadoBusca);
		printf("Interações: %d\n", k);
	}
	else{
		printf("Busca3: Não encontrei!\n");
	}

	
	printf("-------------------------------------\n");
	getch();
}
