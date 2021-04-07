#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct medal{
	int bronze, prata, ouro;
	char country[30];
}MEDAL;


AlfL(char l1, char l2){
	if(l1==l2){
		return 0;
	}else if(l1<l2){
		return l1;
	}else{
		return l2;
	}
}

CompareWords(char* a, char* b){
    int i = 0;
    while(a[i] != '/0' && b[i] != '/0'){
        if(a[i] != b[i]){
            if(a[i] < b[i]) {return a;}
            if(b[i] < a[i]) {return b;}        
        }else{
            i++;
        }
    }
    if(a[i]=='/0'){return a;}
    if(b[i]=='/0'){return b;}
}

main () {
	setlocale(LC_ALL, "Portuguese");
	
	int j;
	scanf("%d", &j);
	
	MEDAL list[j];
	
	printf("Digite o país: ");
	scanf("%")
	
	getchar();
}
