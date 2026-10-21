#include <stdio.h>
 
int main() {
 
    int n, soma= 0, total = 0, i, alunos; 
    
    scanf("%d", &n); 

    for(i = 0; i < n; i++){
        scanf("%d", &alunos);
        soma += (alunos / 3) ;        
    }
    
    total = soma * 3;
    printf("%d\n", total);
 
    return 0;
}   