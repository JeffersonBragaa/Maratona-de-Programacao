#include <stdio.h>
 
int main() {
 
    int b, n, i, d, v, c, controla = 0; 
    
    scanf("%d %d", &b, &n); 
    
    while(b > 0 && n > 0){
        int r[b]; 
        controla = 0;
        for(i = 0; i < b; i++){
            scanf("%d" , &r[i]);
        }
                
        for(i = 0; i < n; i++){
            
            scanf("%d %d %d", &d, &c, &v);
            
            r[d - 1] -= v; 
            r[c - 1] += v;
        }
        
        for(i = 0; i < b; i++){
            if(r[i] < 0){
                controla = 1;
            }
        }
        if(controla == 1){
            printf("N\n");
        }else{
            printf("S\n");
        }
        
        scanf("%d %d", &b, &n); 
    }
     
    return 0;
}