#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

typedef struct pais{
    char pais[30];
    int ouro, prata, bronze;
}PAIS;

PAIS list[500];
PAIS ord[500];
PAIS vazio={"", 0, 0, 0};

Alpha(char* a, char* b){
	int k=0;
	while(a[k]!='\0' && b[k]!='\0'){
		if(a[k]>b[k]) return 1;
		if(a[k]<b[k]) return 0;
		k++;
	}
	if(a[k]=='\0') return 0;
	return 1;
}

main(){

    setlocale(LC_ALL,"Portuguese");
    int k, n;
	
    printf("Informe o número de participantes: ");
    scanf("%d", &n);

    for(k=0; k<n; k++){
        printf("Informe o país e suas respectivas medalhas: ");
        scanf("%s %d %d %d", &list[k].pais, &list[k].ouro, &list[k].prata, &list[k].bronze);
    }
    
    int x;
    int j;
    for(j=0; j<n; j++){
    	PAIS max=vazio;
    	for(k=0; k<n; k++){	
    		if(list[k].ouro > max.ouro){
    			max=list[k];
    			x=k;
			}else if(list[k].ouro==max.ouro){
				if(list[k].prata > max.prata){
					max=list[k];
					x=k;
				}else if(list[k].prata==max.prata){
					if(list[k].bronze>max.bronze){
						max=list[k];
						x=k;
					}else if(list[k].bronze==max.bronze){
						if(Alpha(list[k].pais, max.pais)==0){
							max=list[k];
							x=k;
						}	
					}
				}		
			}
		}
		list[x]=vazio;
		ord[j]=max;
	}
	
	for(k=0; k<n; k++){
		printf("%s %d %d %d\n", ord[k].pais, ord[k].ouro, ord[k].prata, ord[k].bronze);
	}

    getch();

}
