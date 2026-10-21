#include <stdio.h>

int main() {
    int p;
    int soma = 0;

    scanf("%d", &p);

    if (p < 10) {
        soma = p;
    }
    else if (p < 100) {
        soma = 9 + (p - 9) * 2;
    }
    else if (p < 1000) {
        soma = 9 + 90 * 2 + (p - 99) * 3;
    }
    else if (p < 10000) {
        soma = 9 + 90 * 2 + 900 * 3 + (p - 999) * 4;
    }
    else if (p < 100000) {
        soma = 9 + 90 * 2 + 900 * 3 + 9000 * 4
             + (p - 9999) * 5;
    }
    else if (p < 1000000) {
        soma = 9 + 90 * 2 + 900 * 3 + 9000 * 4 + 90000 * 5
             + (p - 99999) * 6;
    }

    printf("%d\n", soma);

    return 0;
}
