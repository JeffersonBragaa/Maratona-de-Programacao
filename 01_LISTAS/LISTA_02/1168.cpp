#include <bits/stdc++.h>

int main() {

    int vet[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int n, leds = 0, temp;
    char numero[102];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        scanf("%101s", numero);
        
        leds = 0;

        for (int j = 0; numero[j] != '\0'; j++) {
            temp = numero[j] - '0';

            leds += vet[temp];
        }
        
        printf("%d leds\n", leds);
    }

    return 0;
}