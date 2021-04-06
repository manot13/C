#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<string.h>

typedef struct contato_{
	char nome[30];
	int idade;
}contato;

contato pessoa;

gravar(){
	FILE* arquivo = fopen("agenda.txt", "w");
	
	do{
		system("cls");
		fflush(stdin);
		printf("Nome: ");
		scanf("%s", &pessoa.nome);
		printf("Idade: ");
		scanf("%d", &pessoa.idade);
		fflush(stdin);
		printf("Deseja continuar [s/n]? ");
		fwrite(&pessoa, sizeof(contato), 1, arquivo);
	}while(getche()=='s');	
	fclose(arquivo);
}

ler(contato* lista){
	FILE* arquivo = fopen("agenda.txt", "r");
	int k=0;
	while(fread(&pessoa, sizeof(contato), 1, arquivo)==1){
		lista[k++]=pessoa;
	}
	fclose(arquivo);
	return k;
}

imprimir(contato* lista, int tam){
	int k;
	for(k=0; k<tam; k++){
		printf("Nome: %s\n", lista[k].nome);
		printf("Idade: %d\n", lista[k].idade);
	}
}

ordenaN(contato* lista, int tam){
	contato aux;
	int k, j;
	
	for(k=0; k<tam-1; k++){
		for(j=k+1; j<tam; j++){
			if(strcmp(lista[k].nome, lista[j].nome)==1){
				aux=lista[k];
				lista[k]=lista[j];
				lista[j]=aux;
			}		
		}
	}
}

ordenaI(contato* lista, int tam){
	contato aux;
	int k, j;
	
	for(k=0; k<tam-1; k++){
		for(j=k+1; j<tam; j++){
			if(lista[k].idade>lista[j].idade){
				aux=lista[k];
				lista[k]=lista[j];
				lista[j]=aux;
			}		
		}
	}
}

buscaON(contato* lista, int tam){
	ordenaN(lista, tam);
	char ctt[20];
	int k;
	
	printf("Digite o nome que deseja buscar: ");
	scanf("%s", &ctt);
	
	for(k=0; k<tam; k++){
		if(strcmp(lista[k].nome, ctt)==0){
			return k;
		}
	}
	return -1;
}

buscaOI(contato* lista, int tam){
	ordenaN(lista, tam);
	int id;
	int k, j;
	
	printf("Digite a idade que deseja buscar: ");
	scanf("%d", &id);
	
	for(k=0; k<tam; k++){
		if(lista[k].idade==id){
			return k;
		}
	}
	return -1; 
}

buscaBN(contato* lista, int tam){
	ordenaN(lista, tam);
	char ctt[20]; 
	
	int ini=0;
	int fim=tam;
	int meio;
	
	printf("Digite o nome que deseja buscar: ");
	scanf("%s", &ctt);
	
	while(ini<=fim){
		meio=(ini+fim)/2;
		if(strcmp(lista[meio].nome, ctt)==1){
			fim=meio-1;
		}
		else if(strcmp(lista[meio].nome, ctt)==-1){
			ini=meio+1;
		}
		else if(strcmp(lista[meio].nome, ctt)==0){
			return meio;
		}
	}
	return -1;
}

buscaBI(contato* lista, int tam){
	ordenaI(lista, tam);
	int id; 
	
	int ini=0;
	int fim=tam;
	int meio;
	
	printf("Digite a idade que deseja buscar: ");
	scanf("%d", &id);
	
	while(ini<=fim){
		meio=(ini+fim)/2;
		if(lista[meio].idade>id){
			fim=meio-1;
		}
		else if(lista[meio].idade<id){
			ini=meio+1;
		}
		else if(lista[meio].idade==id){
			return meio;
		}
	}
	return -1;
}

main(){
	setlocale(LC_ALL, "Portuguese");
	contato lista[100];
	int tam;
	int opcao;
	
	do{
		system("cls");
		printf("1 - Gravar contato\n");
		printf("2 - Ler contato\n");
		printf("3 - Buscar por nome ordenada\n");
		printf("4 - Buscar por idade ordenada\n");
		printf("5 - Imprimir\n");
		printf("6 - Buscar por nome binária\n");
		printf("7 - Bsucar por idade binária\n");
		printf("8 - Sair\n\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				gravar();
			break;
			case 2:
				system("cls");
				tam=ler(lista);
				printf("Seus contatos foram lidos com sucesso!");
				getch();
			break;
			case 3:
				system("cls");
				pessoa=lista[buscaON(lista, tam)];
				printf("Nome: %s\n", pessoa.nome);
				printf("Idade: %d\n", pessoa.idade);
				getch();
			break;
			case 4:
				system("cls");
				pessoa=lista[buscaOI(lista, tam)];
				printf("Nome: %s\n", pessoa.nome);
				printf("Idade: %d\n", pessoa.idade);
				getch();
			break;
			case 5:
				system("cls");
				imprimir(lista, tam);
				getch();		
			break;
			case 6:
				system("cls");
				pessoa=lista[buscaBN(lista, tam)];
				printf("Nome: %s\n", pessoa.nome);
				printf("Idade: %d\n", pessoa.idade);
				getch();
			break;
			case 7:
				system("cls");
				pessoa=lista[buscaBI(lista, tam)];
				printf("Nome: %s\n", pessoa.nome);
				printf("Idade: %d\n", pessoa.idade);
				getch();
			break;
			case 8:
				system("cls");
				printf("Você saiu!");
			break;
			default:
				system("cls");
				printf("Opção inválida!");
				getch();
			break;
		}
	}while(opcao!=8);

	getch();
}