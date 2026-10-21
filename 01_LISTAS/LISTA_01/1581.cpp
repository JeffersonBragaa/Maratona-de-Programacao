#include <bits/stdc++.h>

int main() {

    int n, i, pessoas, j;
    char idioma[20], temp[20];
    int verifica = 1;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {

        scanf("%d", &pessoas);

        verifica = 1;

        for(j = 0; j < pessoas; j++) {

            scanf("%s", idioma);

            if(j == 0) {
                strcpy(temp, idioma);
            }
            else if(strcmp(idioma, temp) != 0) {
                verifica = 0;
            }
        }

        if(verifica) {
            printf("%s\n", temp);
        }
        else {
            printf("ingles\n");
        }
    }

    return 0;
}