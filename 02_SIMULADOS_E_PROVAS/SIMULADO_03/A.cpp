#include <bits/stdc++.h>
using namespace std;

struct Ponto {
    long long x, y;
};

long long orientacao(Ponto a, Ponto b, Ponto c) {
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Ponto> alunos(n);
    for (int i = 0; i < n; i++) {
        cin >> alunos[i].x >> alunos[i].y;
    }

    int melhorRegua = 1;
    int menorDiferenca = n + 1;

    for (int i = 1; i <= m; i++) {
        Ponto a, b;
        cin >> a.x >> a.y >> b.x >> b.y;

        int esquerda = 0;
        int direita = 0;

        for (int j = 0; j < n; j++) {
            if (orientacao(a, b, alunos[j]) > 0) {
                esquerda++;
            } else {
                direita++;
            }
        }

        int diferenca = abs(esquerda - direita);
        if (diferenca < menorDiferenca) {
            menorDiferenca = diferenca;
            melhorRegua = i;
        }
    }

    cout << melhorRegua << '\n';
    return 0;
}