#include <stdio.h>

int main() {

    int n, m, i;

    scanf("%d %d", &n, &m);

    while(m != 0 && n != 0) {

        int t[m];
        int temp[n + 1];
        int cont = 0;

        
        for(i = 0; i < m; i++) {
            scanf("%d", &t[i]);
        }
        for(i = 0; i <= n; i++) {
            temp[i] = 0;
        }
        for(i = 0; i < m; i++) {
            temp[t[i]]++;
        }

        for(i = 1; i <= n; i++) {
            if(temp[i] > 1) {
                cont++;
            }
        }

        printf("%d\n", cont);

        scanf("%d %d", &n, &m);
    }

    return 0;
}