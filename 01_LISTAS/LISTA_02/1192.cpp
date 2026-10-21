#include <stdio.h>
 
int main() {
 
    int n, n1, n2, i, soma = 0, controla = 1;
    char jogo[4];
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        
        scanf("%s", &jogo);
        n1 = jogo[0] - '0';
        n2 = jogo[2] - '0';
        
        if(n1 == n2){
            soma = n1 * n2;
            printf("%d\n", soma);
        }
        else if(jogo[1] >= 'a' && jogo[1] <= 'z'){
            soma = n1 + n2;
            printf("%d\n", soma);
        }
        else{
            soma = n2 - n1;
            printf("%d\n", soma);
        }
    }
    return 0;
}