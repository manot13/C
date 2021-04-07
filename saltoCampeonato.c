#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<locale.h>

typedef struct salto SALTO;
struct salto{
	char	atleta[10];
	float	GD;
	float	notas[7];
};


int ler(SALTO* vetor){
	SALTO pulo;
	FILE* arquivo;
	int k = 0;
	
	arquivo = fopen("dados_torneio.txt", "r"); //r - leitura
	
	system("cls");
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo!\n");
	}
	else{
		while ( fread(&pulo, sizeof(SALTO), 1, arquivo)==1 ){  //enquanto conseguir ler uma linha
			vetor[k++] = pulo;
		}
	}
	fclose(arquivo);
	
	return k;
}


void imprimir(SALTO* vetor, int tam){
	int k;
	system("cls");
	for(k=0; k<tam; k++){
		printf("Atleta: %s\n", vetor[k].atleta);
		printf("GD: %0.2f\n", vetor[k].GD);
		printf("Notas: %0.2f, %0.2f, %0.2f, %0.2f, %0.2f, %0.2f, %0.2f \n", vetor[k].notas[0], vetor[k].notas[1], vetor[k].notas[2], vetor[k].notas[3], vetor[k].notas[4], vetor[k].notas[5], vetor[k].notas[6]);
		printf("-------------------------------------------------------------- \n");
	}
}


void ordena(SALTO* vetor, int tam, int opcao){
	int k, m;
	SALTO aux;
	for(k=0; k<tam-1; k++){
		for(m=k+1; m<tam; m++){
			switch(opcao){
				case 1:	//ordenar por nome do atleta
					if( strcmp(vetor[k].atleta, vetor[m].atleta) == 1 ){
						aux = vetor[k];
						vetor[k] = vetor[m];
						vetor[m] = aux;
					}
				break;
				
				case 2:	//ordenar por grau de dificuldade
					if( vetor[k].GD < vetor[m].GD ){
						aux = vetor[k];
						vetor[k] = vetor[m];
						vetor[m] = aux;
					}
				break;
			}
		}
	}
}

void gravar(){
	SALTO pulo;
	FILE* arquivo;
	
	arquivo = fopen("dados_torneio.txt", "a"); //a - append (adiciona registros ao final) | w - write (sobrepõe os registros que já existam)
	
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo!\n");
	}
	else{
		do{
			system("cls");
			fflush(stdin);
			printf("Digite o nome do atleta: ");
			gets(pulo.atleta);
			
			fflush(stdin);
			printf("Digite o grau de dificuldade: ");
			scanf("%f", &pulo.GD);
			
			fflush(stdin);
			printf("Digite as 7 notas: ");
			scanf("%f %f %f %f %f %f %f", &pulo.notas[0], &pulo.notas[1], &pulo.notas[2], &pulo.notas[3], &pulo.notas[4], &pulo.notas[5], &pulo.notas[6]);
			
			fwrite(&pulo, sizeof(SALTO), 1, arquivo);
			printf("Deseja continuar [s/n] ? ");
		}while(getche()=='s');
	}
	
	fclose(arquivo);
}

void atualizar(SALTO* vetor, int tam){
	int k;
	SALTO pulo;
	FILE* arquivo;
	arquivo = fopen("dados_torneio.txt", "w");
	for(k=0; k<tam; k++){
		fwrite(&pulo, sizeof(SALTO), 1, arquivo);
	}
	fclose(arquivo);
}

main(){
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	
	SALTO torneio[100];
	
	int tam = 0;
	do{
		system("cls");
		printf("1 - Ler Arquivo\n");
		printf("2 - Gravar Arquivo\n");
		printf("3 - Ordenar pelo nome do atleta \n");
		printf("4 - Ordenar pelo grau de dificuldade\n");
		printf("5 - Imprimir\n");
		printf("7 - Atualizar\n");
		printf("6 - Sair\n\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:	//ler arquivo
				system("cls");
				tam = ler(torneio);
				printf("Dados do arquivo lidos com sucesso!\n");
				getch();
			break;
			
			case 2:	//gravar arquivo
				gravar();
			break;
			
			case 3:
				system("cls");
				ordena(torneio, tam, 1);
				printf("Ordenação por nome do atleta realizada com sucesso!\n");
				getch();
			break;
			
			case 4:
				system("cls");
				ordena(torneio, tam, 2);
				printf("Ordenação por grau de dificuldade realizada com sucesso!\n");
				getch();
			break;

			case 5:
				system("cls");
				imprimir(torneio, tam);
				getch();
			break;
			
			case 6:
				printf("Obrigado por sua visita!\n");
			break;
			
			case 7:
				atualizar(torneio, tam);
				system("cls");
				printf("Atualizado com sucesso!");
				getch();
			break;
			
			default:
				printf("Opção inválida!\n");
				getch();
			break;			
		}
	}while(opcao != 6);
	
	getch();
}
