#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

main () {
	setlocale(LC_ALL, "Portuguese");
	
	int a;
	
	printf("Digite a sua idade: ");
	scanf("%d", &a);
	
	if(a>=18 && a<70){
		printf("Você é obrigado a votar!");
	}else if(a<16){
		printf("Você não pode votar!");
	}else if(a>=70||a<18){
		printf("Você não é obrigado a votar!");
	}
	
	getchar();
}
