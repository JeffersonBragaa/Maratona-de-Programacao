#include <stdio.h>
#include <string.h>

int main() {

    int n, t;
    int i;

    while (scanf("%d", &n) && n != 0) {

        int erros[26] = {0};
        int resolvidos[26] = {0};

        int s = 0;
        int p = 0;

        for (i = 0; i < n; i++) {

            char letra;
            char palavra[10];

            scanf(" %c %d %s", &letra, &t, palavra);

            int pos = letra - 'A';

            if (strcmp(palavra, "incorrect") == 0) {

                erros[pos]++;

            } else if (strcmp(palavra, "correct") == 0) {

                if (!resolvidos[pos]) {

                    p += t + (erros[pos] * 20);
                    s++;

                    resolvidos[pos] = 1;
                }
            }
        }

        printf("%d %d\n", s, p);
    }

    return 0;
}