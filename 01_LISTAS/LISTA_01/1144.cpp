#include <stdio.h>
 
int main() {
 
    int n, i, j, seg, ter; 
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = 0; j < 2; j++){
            if(j == 0){
                seg = i*i;
                ter = i * seg;
                printf("%d", i); 
                printf(" %d", seg);
                printf(" %d\n", ter);
            }
            else{
                seg += 1;
                ter += 1;
                printf("%d", i); 
                printf(" %d", seg);
                printf(" %d\n", ter);
            }
        }
        seg = 0;
        ter = 0;
    }
    
 
    return 0;
}