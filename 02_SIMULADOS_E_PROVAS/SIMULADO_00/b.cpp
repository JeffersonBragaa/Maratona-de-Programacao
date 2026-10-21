#include <stdio.h>
/*
gcc –o saida problemaA.c (compila)  ./saida (executa)*/ 

int main(){
	
	int n, i, cont = 0; 
	double c;
	double temp;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		
		scanf("%lf", &c);
		
		while(c > 1){
			temp = c * 0.5; 
			c -= temp;
			cont++;
		}
		
		printf("%d dias\n", cont);
		cont = 0;
	}
	
	
	return 0;
}
