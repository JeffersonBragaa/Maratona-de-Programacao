// #include <bits/stdc++.h>
// #define MAX 100000
// int main (){

//     int n, k, i, j, v; 
//     char c; 
//     int prod;

//     int a[MAX];

//     while(scanf("%d %d", &n, &k) != EOF){
//         for(i = 1; i <= n; i++){
//             scanf("%d", &a[i]); 
//             if(a[i] > 0) a[i] == 1;
//             else if(a [i] < 0) a[i] = -1; 
//             else a[i] = 0;
//         }
//         while(k--){
//             scanf(" %c %d %d", &c, &i, &v); 

//             if (c == 'C'){
//                 a[i] = v; 
//             }else{
//                 prod = 1; 
//                 for(j = i; j <= v; j++){
//                     prod = prod * a[j];
//                 }

//                 if(prod > 0) printf("+"); 
//                 else if(prod == 0) printf("0"); 
//                 else printf("-");
//             }
//         }
//     }

//     return 0;
// }


#include <bits/stdc++.h>
#define MAX 100000
int main (){

    int n, k, i, j, v; 
    char c; 
    int prod;

    int a[MAX];

    while(scanf("%d %d", &n, &k) != EOF){
        for(i = 1; i <= n; i++){
            scanf("%d", &a[i]); 
            if(a[i] > 0) a[i] == 1;
            else if(a [i] < 0) a[i] = -1; 
            else a[i] = 0;
        }
        while(k--){
            scanf(" %c %d %d", &c, &i, &v); 

            if (c == 'C'){
                a[i] = v; 
            }else{
                prod = 1; 
                for(j = i; j <= v; j++){
                    prod = prod * a[j];
                }

                if(prod > 0) printf("+"); 
                else if(prod == 0) printf("0"); 
                else printf("-");
            }
        }
    }

    return 0;
}