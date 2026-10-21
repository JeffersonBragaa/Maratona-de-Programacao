#include <stdio.h>
 
int main() {
    
    int n, i, maior; 
    
    scanf("%d", &n); 
    
    int vet[n];
    for(i = 0; i < n; i++){
        scanf("%d", &vet[i]);
        if(i == 0){
            maior = vet[i];
        }
        else{
            if(maior < vet[i]){
                maior = vet[i]; 
            }
        }
    }
    
    printf("%d\n", maior + 1);
 
    return 0;
}