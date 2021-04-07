#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	
    float h, v;
    float l;
    
    printf("Digite o tempo que ele levou em horas: ");
    scanf("%f", &h);
    printf("Digite a velocidade média: ");
    scanf("%f", &v);
    
    l = v*h/12;
    
    printf("Litros: %.3f", l);
    
    getchar();
}
