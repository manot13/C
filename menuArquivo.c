#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

typedef struct contato{
	char nome[30];
	int idade;	
}CONTATO;

CONTATO ctt;

Gravar(){
	FILE* arquivo;
	arquivo = fopen("agenda.txt", "a");
	char soun;
	
	do{
		system("cls");
		fflush(stdin);
		printf("Digite o nome: ");
		scanf("%s", &ctt.nome);
	
		fflush(stdin);
		printf("Digite a idade: ");
		scanf("%d", &ctt.idade);
		fwrite(&ctt, sizeof(CONTATO), 1, arquivo);
		
		printf("Deseja continuar [s/n]? ");
		scanf("%c", &soun);
	}while(getche()=='s');
	
	fclose(arquivo);
}

Read(){
	FILE* arquivo;
	arquivo = fopen("agenda.txt", "r");
	
	if(arquivo==NULL){
		printf("Problema na execução do arquivo!");
	}else{
		while(fread(&ctt, sizeof(CONTATO), 1, arquivo)==1){
			fflush(stdin);
			printf("Nome: %s\n", ctt.nome);
			printf("Idade: %d\n\n", ctt.idade);
		}
		fclose(arquivo);
	}
}

void Imprimir(CONTATO* vetor, int tam){
	int k;
	for(k=0; k<tam; k++){
		printf("Nome: %s", vetor[k].nome);
		printf("Idade: %d", vetor[k].idade);
		printf("-----------------------------\n");
	}
}

main () {
	setlocale(LC_ALL, "Portuguese");
	
	int option;
	
	do{
		system("cls");
		printf("1 - Gravar\n");
		printf("2 - Imprimir\n");
		printf("3 - Sair\n\n");
		
		fflush(stdin);
		printf("Digite uma opção: ");
		scanf("%d", &option);
		
		switch(option){
		case 1:
			Gravar();
		break;
		case 2:
			Read();
		break;
		case 3:
			system("cls");
			printf("Obrigado pela sua visita!");
		default:
			printf("Opção inválida!");
			getch();
		break;	
	}
}while(option != 3);

	
	getch();
}
