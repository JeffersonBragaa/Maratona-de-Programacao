#include <bits/stdc++.h> 

int main(){
    
    int n, numero = 1, i, cont = 1; 
    
    scanf("%d", &n); 
    
    for(i = 0; i < n; i++){

        printf("%d %d %d PUM\n", numero, numero + 1, numero + 2);
        numero += 4;
    }
    
    return 0;
}