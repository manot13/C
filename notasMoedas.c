#include <stdio.h>
 
int main() {
 
	int N1, N2;
	int n100, n50, n20, n10, n5, n2;
	int m1, m050, m025, m010, m005, m001;
	
	scanf("%d.%d", &N1, &N2);
	
	n100 = N1/100;
		N1 = N1%100;
	n50 = N1/50;
		N1 = N1%50;
	n20 = N1/20;
		N1 = N1%20;
	n10 = N1/10;
		N1 = N1%10;
	n5 = N1/5;
		N1 = N1%5;
	n2 = N1/2;
		N1 = N1%2;
	m1 = N1;
	
	m050 = N2/50;
		N2 = N2%50;
	m025 = N2/25;
		N2 = N2%25;
	m010 = N2/10;
		N2 = N2%10;
	m005 = N2/5;
		N2 = N2%5;
	m001 = N2;
	
	printf("NOTAS:\n");
	printf("%d nota(s) de R$ 100.00\n", n100);
	printf("%d nota(s) de R$ 50.00\n", n50);
	printf("%d nota(s) de R$ 20.00\n", n20);
	printf("%d nota(s) de R$ 10.00\n", n10);
	printf("%d nota(s) de R$ 5.00\n", n5);
	printf("%d nota(s) de R$ 2.00\n", n2);
	
	printf("MOEDAS:\n");
	printf("%d moeda(s) de R$ 1.00\n", m1);
	printf("%d moeda(s) de R$ 0.50\n", m050);
	printf("%d moeda(s) de R$ 0.25\n", m025);
	printf("%d moeda(s) de R$ 0.10\n", m010);
	printf("%d moeda(s) de R$ 0.05\n", m005);
	printf("%d moeda(s) de R$ 0.01\n", m001);
 
    return 0;
}
