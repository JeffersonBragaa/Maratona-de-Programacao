#include <stdio.h>

int main() {

    int a, d;

    scanf("%d %d", &a, &d);

    while(a != 0 && d != 0) {

        int atacantes[a];
        int defensores[d];

        int i;

        for(i = 0; i < a; i++) {
            scanf("%d", &atacantes[i]);
        }

        for(i = 0; i < d; i++) {
            scanf("%d", &defensores[i]);
        }

        int menor = defensores[0];
        int segundo_menor = defensores[1];

        if(segundo_menor < menor) {
            int temp = menor;
            menor = segundo_menor;
            segundo_menor = temp;
        }

        for(i = 2; i < d; i++) {

            if(defensores[i] < menor) {
                segundo_menor = menor;
                menor = defensores[i];
            }
            else if(defensores[i] < segundo_menor) {
                segundo_menor = defensores[i];
            }
        }

        int impedimento = 0;

        for(i = 0; i < a; i++) {

            if(atacantes[i] < segundo_menor) {
                impedimento = 1;
                break;
            }
        }

        if(impedimento) {
            printf("Y\n");
        }
        else {
            printf("N\n");
        }

        scanf("%d %d", &a, &d);
    }

    return 0;
}