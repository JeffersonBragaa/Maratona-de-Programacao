#include <stdio.h>
 
int main() {
 
    int n, l, i, j, soma = 0, el = 0; 
    char vet[50]; 
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        scanf("%d", &l);
        while(el < l){
            scanf("%s", vet);
            for(j = 0; vet[j] != '\0'; j++){
                soma += (vet[j] - 'A') + el + j; 
            }
            el++;
        }
        printf("%d\n", soma); 
        soma = 0;
        el = 0; 
    }
    return 0;
}