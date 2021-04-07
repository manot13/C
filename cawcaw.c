#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

w(int a, int b){
	int j;
	int i=1;
	for(j=0; j<b; j++){
		i*=a;
	}
	return i;
}

Code(char* a){
	int result = 0;
	int k;
	for(k=0; k<2; k++){
		if(a[k]=='*'){
			result+=pow(2, 2-k);
		}
	}
	return result;
}

Scream(char* a){
	int n = sizeof(a) / sizeof(a[0]);
	int l;
	int result=0;
	int result2=0;
	for(l=0; l<n; l++){
		if(a[l]=='*'||a[l]=='-'){
			char b[3];
			sprintf(b, "%c%c%c", a[l], a[l+1], a[l+2]);
			printf("%d", pow(2, 1));
			result+=Code(b);
			l+=2;
		}
		if(a[l]=='c'){
			l+=5;
			result2+=result;
			result=0;
		}
	}
	return result2;
}

main(){
	char texto[90];
	scanf("%s", texto);
	printf("%d", Scream(texto));
	
	getchar();
}
