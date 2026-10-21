#include <bits/stdc++.h>
using namespace std;


int main () {
    
    int d, dia, mes, ano; 

    cin >> d; 


    ano = d / 365; 
    d = d - (ano * 365); 
    printf("%d ano(s)\n", ano); 
    
    mes = d / 30; 
    d = d - (mes * 30); 
    printf("%d mes(es)\n", mes);
    printf("%d dia(s)\n", d);

    return 0;
}