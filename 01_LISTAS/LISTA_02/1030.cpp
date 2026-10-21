#include <bits/stdc++.h>

int main (){
    
    int nc, pessoas, casa, i, k, j; 
    int vet[pessoas] = {0}; 
    int controla = 1;
    int cont = 0;

    scanf("%d"); 

    for(i = 0; i < nc; i++){
        
        scanf("%d %d", &pessoas, &casa);
        while(controla != 0){
            for(k = casa; k <= pessoas; k += casa){
                if(vet[k] == 0){
                    vet[k] = 1; 
                    cont++;
                    k += 1;
                }

                if(cont + 1 == pessoas ){
                    cont = 0;
                    break;
                }

                if(k + casa > pessoas){
                    k -= pessoas; 
                    casa -= k;
                    
                    if(casa == 0){
                        k = 1;
                    }else{
                        k = casa + 1;
                    }

                    
                }
            }

        }
        for(j = 1; j <= pessoas; j++){
            if(vet[i] == 0){
                printf("Case %d: %d\n", i, j);
            }
        }
        
    }
    
    return 0;
}