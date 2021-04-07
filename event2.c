#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct event{
	int dia;
	int hora;
	int min;
	int seg;
}EVENT;

EVENT inicial;
EVENT final;
EVENT dE;

EVENT CalcEvent(EVENT a, EVENT b){
	b.dia-=a.dia;
	b.hora-=a.hora;
	b.min-=a.min;
	b.seg-=a.seg;
	return b;
}

main () {
	setlocale(LC_ALL, "Portuguese");

	printf("Hora e data de início do evento: ");
	fflush(stdin);
	scanf("%d", &inicial.dia);
	fflush(stdin);
	scanf("%d:%d:%d", &inicial.hora, &inicial.min, &inicial.seg);
	
	system("cls");
	printf("Hora e data do final do evento: ");
	fflush(stdin);
	scanf("%d", &final.dia);
	fflush(stdin);
	scanf("%d:%d:%d", &final.hora, &final.min, &final.seg);
	
	dE = CalcEvent(inicial, final);
	
	printf("O evento durou: %d Dias, %d Horas, %d Minutos e %d Segundos", dE.dia, dE.hora, dE.min, dE.seg);
		
	getchar();
}
