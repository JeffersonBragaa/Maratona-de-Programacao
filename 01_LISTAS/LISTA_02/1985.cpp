#include <stdio.h>
 
int main() {
 
    
    int n, i, p, q; 
    double pedido, soma = 0;;
    scanf("%d", &n); 
    
    for(i = 0; i < n; i++){
        scanf("%d %d", &p, &q); 
        
        pedido = p % 10;
        pedido = (pedido + 0.5) * q;
        soma += pedido;
    }
    
    printf("%.2f\n", soma);
    return 0;
}