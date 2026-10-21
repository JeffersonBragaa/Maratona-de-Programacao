#include <bits/stdc++.h>

int main() {

    int i, t, n, tam;
    long long soma;
    char k[25];

    scanf("%d", &t);

    for(i = 0; i < t; i++){
        scanf("%d %24s", &n, k);
        tam = strlen(k);         

        soma = 1;
        while(n >= 1){
            soma *= n;
            n -= tam;
        }

        printf("%lld\n", soma);
    }

    return 0;
}