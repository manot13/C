#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

typedef struct prod{
	int codigo;
	char nome[30];
	float preco;
}PROD;

PROD lista;

void gravar(){
	FILE* arquivo = fopen("estoque.txt", "a");
	system("cls");
	if(arquivo==NULL){
		printf("Problemas na abertura do arquivo!");
	}else{
		do{
			fflush(stdin);
			printf("Digite o nome do produto: ");
			scanf("%s", &lista.nome);
			fflush(stdin);
			printf("Digite o preço do produto: ");
			fflush(stdin);
			scanf("%f", &lista.preco);
			fflush(stdin);
			printf("Digite o código do produto: ");
			scanf("%d", &lista.codigo);
			
			fwrite(&lista, sizeof(PROD), 1, arquivo);
			
			fflush(stdin);
			printf("Deseja continuar[s/n]?");	
		}while(getchar()=='s');
	}
	fclose(arquivo);
}

ler(PROD* vet){
	FILE* arquivo = fopen("estoque.txt", "r");
	int k=0;
	if(arquivo==NULL){
		printf("Problemas na abertura do arquivo!");
	}else{
		while(fread(&vet[k], sizeof(PROD), 1, arquivo)==1){
			vet[k++] = lista;
		}
	}
	fclose(arquivo);
}

int buscanome1(PROD* vet, int tam, char* searchname){
	int k;
	for(k=0; k<tam; k++){
		if(strcmp(vet[k].nome, searchname)==0){
			return k;
		}
	}
	return -1;
}

int buscacod1(PROD* vet, int tam, int codbuscado){
	int k;
	for(k=0; k<tam; k++){
		if(vet[k].codigo==codbuscado){
			return k;
		}
	}
	return -1;
}

int buscapreco1(PROD* vet, int tam, float precobuscado){
	int k;
	for(k=0; k<tam; k++){
		if(vet[k].preco==precobuscado){
			return k;
		}
	}
	return -1;
}

void ordenaCOD(PROD* vet, int tam){
	int k, j;
	PROD aux;
	for(k=0; k<tam-1, k++;){
		for(j=k+1; j<tam; j++){
			if(vet[k].codigo>vet[j].codigo){
				aux=vet[k];
				vet[k]=vet[j];
				vet[j]=aux;
			}
		}
	}
}

void ordenaPRECO(PROD* vet, int tam){
	int k, j;
	PROD aux;
	for(k=0; k<tam-1; k++){
		for(j=k+1; j<tam; j++){
			if(vet[k].preco>vet[j].preco){
				aux=vet[k];
				vet[k]=vet[j];
				vet[j]=aux;
			}
		}
	}
}

void ordenaNOME(PROD* vet, int tam){
	int k, j;
	PROD aux;
	for(k=0; k<tam-1; k++){
		for(j=k+1; j<tam; j++){
			if(strcmp(vet[k].nome, vet[j].nome)==1){
				aux=vet[k];
				vet[k]=vet[j];
				vet[j]=aux;
			}
		}
	}
}

int buscaOrdenadaN(PROD* vet, int tam, char* nomebuscado){
	ordenaNOME(vet, tam);
	int k;
	for(k=0; k<tam; k++){
		if(strcmp(vet[k].nome, nomebuscado)==0){
			return k;
		}
		if(strcmp(vet[k].nome, nomebuscado)==1){
			return -1;
		}
	}
}

int buscaOrdenadaC(PROD* vet, int tam, int codbuscado){
	ordenaCOD(vet, tam);
	int k;
	for(k=0; k<tam; k++){
		if(vet[k].codigo==codbuscado){
			return k;
		}
		if(vet[k].codigo>codbuscado){
			return -1;
		}
	}
}

int buscaBinariaN(PROD* vet, int tam, char* nomebuscado){
	ordenaNOME(vet, tam);
	int ini=0;
	int fim=tam;
	int meio;
	while(ini<=fim){
		meio = (ini+fim)/2;
		if(strcmp(vet[meio].nome, nomebuscado)==1){
			fim = meio-1;
		}
		else if(strcmp(vet[meio].nome, nomebuscado)==1){
			ini = meio+1;
		}
		else if(strcmp(vet[meio].nome, nomebuscado)==0){
			return meio;
		}
	}
	return -1;
}

int buscaBinariaC(PROD* vet, int tam, int codbuscado){
	ordenaCOD(vet, tam);
	int ini=0;
	int fim=tam;
	int meio;
	while(ini<=fim){
		if(vet[meio].codigo>codbuscado){
			fim = meio-1;
		}
		else if(vet[meio].codigo>codbuscado){
			ini = meio+1;
		}
		else if(vet[meio].codigo==codbuscado){
			return meio;
		}
	}
}

void imprimir(PROD* vet, int tam){
	int k;
	for(k=0; k<tam; k++){
		printf("%s\n", &vet[k].nome);
		printf("%f\n", &vet[k].preco);
		printf("%d\n", &vet[k].codigo);
	}
}

void att(PROD* vet, int tam){
	FILE* arquivo = fopen("estoque.txt", "w");
	int k;
	
	if(arquivo==NULL){
		printf("Problemas na abertura do arquivo!\n");
	}else{
		for(k=0; k<tam; k++){
			fwrite(&vet[k], sizeof(PROD), 1, arquivo);
		}
	}
	fclose(arquivo);
}

main () {
	setlocale(LC_ALL, "Portuguese");
	PROD lista[100];
	int opcao;
	int tam=0;
	char nome[20];
	int pos;
	int cod;
	float preco;
	do{
		system("cls");
		printf("1 - Gravar arquivo\n");
		printf("2 - Ler arquivo\n");
		printf("3 - Imprimir\n");
		printf("4 - Buscar sequencialmente por um código\n");
		printf("5 - Buscar sequencialmente por um nome\n");
		printf("6 - Buscar sequencialmente por um preço\n");
		printf("7 - Buscar ordenadamente por um código\n");
		printf("8 - Buscar ordenadamente por um nome\n");
		printf("9 - Buscar binariamente por um código\n");
		printf("10 - Buscar binariamente por um nome\n");
		printf("11 - Atualizar arquivo\n");
		printf("12 - Sair\n\n");
		printf("Digite uma opão: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				gravar();
			break;
			
			case 2: 
				tam=ler(lista);
				printf("Arquivos lidos com sucesso!\n");
				getchar();
			break;
			
			case 3:
				imprimir(lista, tam);
				getchar();
			break;
			
			case 4:
				pos = buscacod1(lista, tam, cod);
				printf("Digite o código a pesquisar: ");
				scanf("%d", &cod);
				if(pos==-1){
					printf("O código não existe na lista!");
				}else{
					printf("O código foi achado na posição: %d\n", pos);
					getchar();
				}
			break;
			
			case 5:
				pos = buscanome1(lista, tam, nome);
				printf("Digite o nome a pesquisar: ");
				scanf("%s", &nome);
				if(pos==-1){
					printf("O produto não existe na lista!");
				}else{
					printf("O produto foi encontrado na posição: %d\n", pos);
					getchar();
				}
			break;
			
			case 6:
				pos = buscapreco1(lista, tam, preco);
				printf("Digite o preço a pesquisar: ");
				scanf("%f", &preco);
				if(pos==-1){
					printf("O preço não existe na lista!");
				}else{
					printf("O preço foi encontrado na posição: %d\n", pos);
					getchar();
				}
			break;
			
			case 7:
				pos = buscaOrdenadaC(lista, tam, cod);
				printf("Digite o código a pesquisar: ");
				scanf("%d", &cod);
				if(pos==-1){
					printf("O código não existe na lista!");
				}else{
					printf("O código foi encontrado na posição: %d\n", pos);
					getchar();
				}
			break;
			
			case 8:
				pos = buscaOrdenadaN(lista, tam, nome);
				printf("Digite o nome a pesquisar: ");
				scanf("%s", &nome);
				if(pos==-1){
					printf("Produto não existe na lista!");
				}else{
					printf("O produto foi encontrado na posição: %d\n", pos);
					getchar();
				}
			break;
			
			case 9:
				pos = buscaBinariaC(lista, tam, cod);
				printf("Digite o código a pesquisar: ");
				scanf("%d", &cod);
				if(pos==-1){
					printf("O código não existe na lista!");
				}else{
					printf("O código foi encontrado na posição: %d\n", pos);
					getchar();
				}
			break;
			
			case 10:
				pos = buscaBinariaN(lista, tam, nome);
				printf("Digite o nome a pesquisar: ");
				scanf("%s", &nome);
				if(pos==-1){
					printf("Produto não existe na lista!");
				}else{
					printf("O produto foi encontrado na posição: %d\n", pos);
					getchar();
				}
			break;
			
			case 11:
				att(lista, tam);
				printf("Arquivo atualizado com sucesso!\n\n");
				getchar();
			break;
			
			case 12:
				printf("Obrigado pela visita!\n");
			break;
			
			default:
				printf("Opção inválida!\n");
				getchar();
			break;
		}
	}while(opcao!=12);
	
	getchar();
}
