
#include <bits/stdc++.h>
using namespace std;

struct Ponto {
    long long x, y;
};

long long produto(Ponto a, Ponto b) {
    return a.x * b.y - a.y * b.x;
}

long long orientacao(Ponto a, Ponto b, Ponto c) {
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int B, N;

    while (cin >> B >> N && (B != 0 || N != 0)) {
        Ponto origem;
        cin >> origem.x >> origem.y;

        int n = N - 1;
        vector<Ponto> pontos(2 * n);

        for (int i = 0; i < n; i++) {
            cin >> pontos[i].x >> pontos[i].y;

            pontos[i].x -= origem.x;
            pontos[i].y -= origem.y;
        }

        sort(pontos.begin(), pontos.begin() + n,
            [](Ponto a, Ponto b) {
                return atan2((double)a.y, (double)a.x)
                     < atan2((double)b.y, (double)b.x);
            });

        for (int i = 0; i < n; i++) {
            pontos[i + n] = pontos[i];
        }

        const long long INF = (1LL << 60);

        vector<vector<long long>> area(
            2 * n, vector<long long>(2 * n, -1)
        );

        for (int i = 0; i < n; i++) {
            vector<Ponto> pilha;
            pilha.push_back({0, 0});

            long long soma = 0;

            for (int j = i; j < i + n; j++) {
                if (j > i && produto(pontos[i], pontos[j]) <= 0) {
                    break;
                }

                while (pilha.size() >= 2 &&
                       orientacao(pilha[pilha.size() - 2],
                                  pilha.back(), pontos[j]) <= 0) {

                    soma -= produto(
                        pilha[pilha.size() - 2], pilha.back()
                    );

                    pilha.pop_back();
                }

                soma += produto(pilha.back(), pontos[j]);
                pilha.push_back(pontos[j]);

                if (j > i) {
                    area[i][j] = soma;
                }
            }
        }

        long long resposta = INF;

        for (int inicio = 0; inicio < n; inicio++) {
            vector<vector<long long>> dp(
                B + 1, vector<long long>(n + 1, INF)
            );

            dp[0][0] = 0;

            for (int k = 1; k <= B; k++) {
                for (int fim = 2 * k;
                     fim <= n - 2 * (B - k); fim++) {

                    for (int j = 2 * (k - 1); j <= fim - 2; j++) {
                        long long valor = area[inicio + j][inicio + fim - 1];

                        if (dp[k - 1][j] == INF || valor == -1) {
                            continue;
                        }

                        dp[k][fim] = min(
                            dp[k][fim],
                            dp[k - 1][j] + valor
                        );
                    }
                }
            }

            resposta = min(resposta, dp[B][n]);
        }

        cout << fixed << setprecision(2);
        cout << resposta / 2.0 << '\n';
    }

    return 0;
}
