#include <stdio.h>

int main() {

    int n, m; 
    int i;
    long long int soma = 1; 
    long long int soma2 = 1;

    while(scanf("%d %d", &m, &n) != EOF){
        
        if(m == 0){
            soma = 1;
        }else{
            for(i = m - 1; i > 0; i--){
                soma += i * soma;
            }
        }
            
        if(n == 0){
            soma2 = 1;
        }else{
            for(i = n - 1; i > 0; i--){
                soma2 += i * soma2;
            }
        }
        
        printf("%lld\n", soma + soma2);
        soma = 1; 
        soma2 = 1;
    }
    return 0;


}