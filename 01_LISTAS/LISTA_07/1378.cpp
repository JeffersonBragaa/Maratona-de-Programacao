#include <bits/stdc++.h>
using namespace std;

struct Ponto {
    long long x, y;
};

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<Ponto> pontos(n);

        for (int i = 0; i < n; i++) {
            cin >> pontos[i].x >> pontos[i].y;
        }

        long long total = 0;

        for (int i = 0; i < n; i++) {
            vector<long long> distancias;

            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                long long dx = pontos[i].x - pontos[j].x;
                long long dy = pontos[i].y - pontos[j].y;

                long long distancia = dx * dx + dy * dy;

                distancias.push_back(distancia);
            }

            sort(distancias.begin(), distancias.end());

            long long quantidade = 1;

            for (int j = 1; j < (int)distancias.size(); j++) {
                if (distancias[j] == distancias[j - 1]) {
                    quantidade++;
                }
                else {
                    total += quantidade * (quantidade - 1) / 2;
                    quantidade = 1;
                }
            }

            total += quantidade * (quantidade - 1) / 2;
        }

        cout << total << endl;
    }

    return 0;
}
