#include <bits/stdc++.h> 

int main(){
    
    
    int k, i; 
    long int n, m, x, y; 
    
    scanf("%d", &k);

    scanf("%ld %ld", &n, &m);

    while(k != 0){

        for(i = 0; i < k; i++){
            scanf("%ld %ld", &x, &y);

            if(x > n &&  y > m){
                printf("NE\n");
            }
            else if(x > n && y < m){
                printf("SE\n");
            }
            else if(x < n &&  y > m ){
                printf("NO\n");
            }
            else if(x < n && y < m){
                printf("SO\n");
            }else{
                printf("divisa\n");
            }
        }
        
        scanf("%d", &k);
        scanf("%ld %ld", &n, &m);

    }

    
    return 0;
}