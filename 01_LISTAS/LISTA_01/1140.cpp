#include <bits/stdc++.h>

int main(){
    
    char frase[50*20]; 
    char temp;
    int i = 0;
    char letra;
    int verifica = 1;
    char teste;
  
    scanf("%[^\n]", frase);
    
    while (frase[0] != '*')
    {
        letra = tolower(frase[0]);
        verifica = 1;
        for(i = 1; frase[i] != '\0' ; i++){

            
            temp = frase[i];

            if(temp == ' '){
                temp = tolower(frase[i + 1]); 
                if(temp == letra){
                    verifica = 1; 
                }else{
                    printf("N\n"); 
                    verifica = 0;
                    break;
                }
            }
            
        }
        if(verifica) printf("Y\n"); 

        scanf(" %[^\n]", frase);
    }
    

    return 0;
}