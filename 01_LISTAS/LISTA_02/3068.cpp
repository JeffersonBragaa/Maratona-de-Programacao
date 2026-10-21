#include <bits/stdc++.h>

int main (){
    
    int x1, y1, x2, y2, n, x, y, i, xMaior, xMenor, yMaior, yMenor, cont = 0, teste = 1; 

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 

    while(x1 || y1 || x2|| y2){
        scanf("%d", &n); 
        printf("Teste %d\n", teste);
        for(i = 0; i < n; i++){
            scanf("%d %d", &x, &y);

            if(x1 > x2){
                xMaior = x1; 
                xMenor = x2;
            }else{
                xMaior = x2; 
                xMenor = x1;
            }

            if(y1 > y2){
                yMaior = y1; 
                yMenor = y2;
            }else{
                yMaior = y2; 
                yMenor = y1;
            }

            if((xMenor <= x && x <= xMaior) && (yMenor <= y  && y <= yMaior)){
                cont++;
            }
        }
        printf("%d\n", cont); 
        cont = 0;
        teste++;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 

    }
    
    return 0;
}