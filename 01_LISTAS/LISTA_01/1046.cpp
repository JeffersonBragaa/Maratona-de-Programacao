#include <bits/stdc++.h>

int main(){

    int hora_ini; 
    int hora_fim;
    int duracao;
    int i;


    scanf("%d %d", &hora_ini, &hora_fim);

    if(hora_ini < hora_fim){
        duracao = hora_fim - hora_ini; 
        printf("O JOGO DUROU %d HORA(S)\n", duracao);
    }
    else if (hora_fim == hora_ini)
    {
        printf("O JOGO DUROU 24 HORA(S)\n");

    }
    else{
        hora_fim = (hora_fim * 60) + (60 * 24);
        hora_ini = hora_ini * 60; 
        
        duracao = (hora_fim - hora_ini) / 60;

        printf("O JOGO DUROU %d HORA(S)\n", duracao);
    }
    


    return 0;
}