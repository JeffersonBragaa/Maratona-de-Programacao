#include <bits/stdc++.h>

int main()
{

    int vet[12] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
    double n;
    int i, divi = 0, resto = 0;
    int escreve_nota = 0, escreve_moeda = 0;

    scanf("%lf", &n);

    n = n * 100;

    for (i = 0; i < 12; i++)
    {

        if (escreve_nota == 0)
        {
            printf("NOTAS:\n");
            escreve_nota = 1;
        }
        divi = n / vet[i];
        resto = (int)n % vet[i];
        n = resto;
        if (i < 6)
        {
            printf("%d nota(s) de R$ %.2f\n", divi, (vet[i] / 100.0));
        }
        else
        {
            if (escreve_moeda == 0 && n < 200)
            {
                printf("MOEDAS:\n");
                escreve_moeda = 1;
            }
            printf("%d moeda(s) de R$ %.2f\n", divi, (vet[i] / 100.0));
        }
    }
    return 0;
}