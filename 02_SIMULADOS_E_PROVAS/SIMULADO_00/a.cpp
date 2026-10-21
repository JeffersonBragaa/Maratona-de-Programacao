#include <bits/stdc++.h>

int main () {

    int n, t, i, comeca, termina, j, temp; 
    
    scanf("%d %d", &n, &t);

    while(n != 0 && t != 0 ){
        int v_cima[n];
        int v_baixo[n]; 

        for(i = 0; i < n; i++){
            scanf("%d", &v_cima[i]);
        }
        
        for(i = 0; i < n; i++){
            scanf("%d", &v_baixo[i]);
        }

        for(i = 0; i < t; i++){
            scanf("%d %d", &comeca, &termina); 

            for(j = comeca - 1; j < termina; j++){
                temp = v_cima[j]; 
                v_cima[j] = v_baixo[j]; 
                v_baixo[j] = temp;
            }
        }
        
        for(i = 0; i < n; i++){
            printf("%d ", v_cima[i]);
        }


        scanf("%d %d", &n, &t);

    }
    return 0; 
}


/* usar um vetor de controle com 0 e 1, atravez do i e j+1 para trocar os vetores que estao sendo printados 
    
**so nao entendi a parte que quando ja ta 1 ele nao inverte o valor do vetor de controle, pois a cada posicao que vou trocar eu tenho que adicionar o 1 no vetor de controle que indica que eiu devo mudar o vetor que estou imprimindo.

    usar tambem o MAXX 
*/