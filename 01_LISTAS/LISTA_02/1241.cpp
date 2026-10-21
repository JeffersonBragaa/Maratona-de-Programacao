#include <stdio.h>

int main() {
    int n, i, j, verifica;
    char a[1000]; 
    char b[1000]; 
    int lena, lenb;

    if (scanf("%d", &n) != 1) return 0;

    for (i = 0; i < n; i++) {
        scanf("%s %s", a, b);

        lena = 0;
        lenb = 0;
        for (j = 0; a[j] != '\0'; j++) lena++;
        for (j = 0; b[j] != '\0'; j++) lenb++;

        if (lenb > lena) {
            printf("nao encaixa\n");
        } else {
            verifica = 1;

            for (j = 0; j < lenb; j++) {
                if (a[lena - lenb + j] != b[j]) {
                    verifica = 0;
                    break;
                }
            }

            if (verifica) {
                printf("encaixa\n");
            } else {
                printf("nao encaixa\n");
            }
        }
    }

    return 0;
}