#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

// Matrizes globais para evitar ocupar a pilha com grandes tabelas.
int value[N][N];
int sum[N][N];

int main() {
    int n;
    cin >> n;

    for (int y=0; y<n; y++) {
        for (int x=0; x<n; x++) {
            cin >> value[y][x];
        }
    }

    // sum[y][x]: maior soma de um caminho de (0,0) até (y,x).
    for (int y=0; y<n; y++) {
        for (int x=0; x<n; x++) {
            // Origem: o caminho começa nesta célula.
            if (y==0 && x==0)
                sum[y][x] = value[y][x];

            // Primeira linha: só pode chegar pela esquerda.
            else if (y==0)
                sum[y][x] = sum[y][x-1] + value[y][x];

            // Primeira coluna: só pode chegar de cima.
            else if (x==0)
                sum[y][x] = sum[y-1][x] + value[y][x];

            // Interior: escolhe a maior soma anterior.
            else
                sum[y][x] = max(sum[y][x-1], sum[y-1][x]) + value[y][x];
        }
    }

    cout << sum[n-1][n-1] << '\n';

    return 0;
}
