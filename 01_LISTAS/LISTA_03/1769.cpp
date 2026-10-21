#include <bits/stdc++.h>
using namespace std;

int main () {

    string cpf; 
    int i, j, k , soma1, soma2, resto1, resto2, num; 

    while(cin >> cpf){
        k = 1;
        j = 9;
        soma1 = 0;
        soma2 = 0;

        for(i = 0; i < 11; i++){
            
            if(cpf[i] != '.' && cpf[i] != '-'){
                num = cpf[i] - '0';
                soma1 += (num * k);
                soma2 += (num * j);
                j--;
                k++;    
            }
            
        }
    
        resto1 = soma1 % 11;
        resto2 = soma2 % 11;
    
        if(resto1 == 10){
            resto1 = 0;
        }
        if(resto2 == 10){
            resto2 = 0;
        }
    
        if(resto1 == (cpf[12] - '0') && resto2 == (cpf[13] - '0')){
            cout << "CPF valido" << endl;
        }
        else{
            cout << "CPF invalido" << endl;
        }

    }

    return 0;
}