#include <bits/stdc++.h>
using namespace std;

 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
     
     int n, x, i; 
     bool verifica = true;
     
     cin >> n;
     while(n--){
         cin >> x; 
         if(x == 2) {
             cout << x << " eh primo\n";
         }else{
             for(i = 2; i < x; i++){
                 if(x % i == 0){
                     cout << x << " nao eh primo\n";
                     verifica = false;
                     break;
                 }
             }
             
             if(verifica) cout << x << " eh primo\n";
             verifica = true;
         }
     }
 
    return 0;
}