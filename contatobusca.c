#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<locale.h>

typedef struct contato CONTATO;
struct contato{
	char	nome[30];
	int		idade;
};

int lerArquivo(CONTATO* vetor){
	CONTATO ctt;
	int k=0;
	FILE* arquivo;
	
	arquivo = fopen("agenda.txt", "r");
	
	system("cls");
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo!\n");
	}
	else{
		while ( fread(&ctt, sizeof(CONTATO), 1, arquivo)==1 ){
			vetor[k++] = ctt;
		}
	}
	fclose(arquivo);
	return k;
}

void imprimir(CONTATO* vetor, int tam){
	int k;
	for(k=0; k<tam; k++){
		printf("Nome: %s\n", vetor[k].nome);
		printf("Idade: %d\n", vetor[k].idade);
		printf("---------------------------\n");
	}
}


void ordena(CONTATO* vetor, int tam, int opcao){
	int k, m;
	CONTATO aux;
	
	for(k=0; k<tam-1; k++){
		for(m=k+1; m<tam; m++){
			switch(opcao){
				case 1: //ordenar por nome
					if ( strcmp(vetor[k].nome, vetor[m].nome) == 1 ) {
						aux = vetor[k];
						vetor[k] = vetor[m];
						vetor[m] = aux;
					}
				break;
				
				case 2: //ordenar por idade
					if ( vetor[k].idade < vetor[m].idade ){
						aux = vetor[k];
						vetor[k] = vetor[m];
						vetor[m] = aux;
					}
				break;
			}
		}
	}
}


void gravarArquivo(){
	CONTATO ctt;
	FILE* arquivo;
	
	arquivo = fopen("agenda.txt", "a");
	
	system("cls");
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo!\n");
	}
	else{
		do{
			system("cls");
			fflush(stdin);
			printf("Digite o nome: ");
			gets(ctt.nome);
			
			printf("Digite a idade: ");
			scanf("%d", &ctt.idade);
			
			fwrite(&ctt, sizeof(CONTATO), 1, arquivo);
			
			printf("Deseja continuar [s/n] ? ");
		}while(getche()=='s');
	}
	fclose(arquivo);
}


void atualiza(CONTATO* vetor, int tam){
	CONTATO ctt;
	FILE* arquivo;
	int k;
	
	arquivo = fopen("agenda.txt", "w");
	
	system("cls");
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo!\n");
	}
	else{
		for(k=0; k<tam; k++){
			fwrite(&vetor[k], sizeof(CONTATO), 1, arquivo);
		}
	}
	fclose(arquivo);
}

int busca3(CONTATO vetor, int tam, int opcao){
	
}

main(){
	CONTATO contatos[100];
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	int tam;
	
	do{
		system("cls");
		printf("1 - Ler Arquivo\n");
		printf("2 - Gravar Arquivo\n");
		printf("3 - Ordenar por nome\n");
		printf("4 - Ordenar por idade\n");
		printf("5 - Imprimir\n");
		printf("6 - Atualiza arquivo\n");
		printf("7 - Buscar por idade\n");
		printf("8 - Buscar por nome\n");
		printf("9 - Sair\n\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:	//ler arquivo
				tam = lerArquivo(contatos);
				printf("Informações recuperadas do arquivo!\n");
				getch();
			break;
			
			case 2:	//gravar arquivo
				gravarArquivo();
				getch();
			break;
			
			case 3:
				ordena(contatos, tam, 1);
				printf("Ordenação por nome realizada com sucesso!");
				getch();
			break;

			case 4:
				ordena(contatos, tam, 2);
				printf("Ordenação por idade realizada com sucesso!");
				getch();
			break;
			
			case 5:
				imprimir(contatos, tam);
				getch();
			break;
			
			case 6:
				atualiza(contatos, tam);
				printf("Arquivo atualizado com sucesso!\n");
				getch();
			break;
			
			case 7:
				printf("Obrigado por sua visita!\n");
			break;
			
			default:
				printf("Opção inválida!\n");
				getch();
			break;			
		}
	}while(opcao != 9);
	
	getch();
}
