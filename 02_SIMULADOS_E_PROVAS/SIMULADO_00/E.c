#include <stdio.h>

int main() {
    
    int n;
    int resto, atual, temp = 0, soma = 0; 
    
    scanf("%d", &n);

    while(n != 0){
        temp = n;
        while(temp > 10){
            
            resto = temp % 10; 
            atual = temp / 10; 
            soma += atual; 
            temp = resto;  
        }

        soma += resto;

        if(n % soma == 0){
            printf("%d\n", n);
            scanf("%d", &n);
            soma = 0;
        }else{
            n++; 
            soma = 0;
        }

    }

    return 0;
}
