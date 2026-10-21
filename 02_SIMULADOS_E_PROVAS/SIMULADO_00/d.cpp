#include <stdio.h> 

int main (){

	
	
	int n, h, i, cont = 0; 
	
	scanf("%d %d", &n, &h); 
	int vet[n];
	
	for(i = 0; i < n; i++){
		scanf("%d", &vet[i]); 
		
		if(vet[i] <= h){
			cont++;
		}
	}
	
	
	printf("%d\n", cont);
	
	return 0;
}
