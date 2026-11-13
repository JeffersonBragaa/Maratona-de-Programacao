
#include <bits/stdc++.h>
using namespace std;

struct Ponto {
    long long x, y;
};

bool comparar(Ponto a, Ponto b) {
    if (a.x != b.x)
        return a.x < b.x;

    return a.y < b.y;
}

long long orientacao(Ponto a, Ponto b, Ponto c) {
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

int main() {
    vector<Ponto> p(5);

    while (true) {
        bool fim = true;

        for (int i = 0; i < 5; i++) {
            if (!(cin >> p[i].x >> p[i].y))
                return 0;

            if (p[i].x != 0 || p[i].y != 0)
                fim = false;
        }

        if (fim)
            break;

        long long maior = 0;

        for (int i = 0; i < 5; i++) {
            vector<Ponto> pontos;

            for (int j = 0; j < 5; j++) {
                if (i != j)
                    pontos.push_back(p[j]);
            }

            sort(pontos.begin(), pontos.end(), comparar);

            int n = pontos.size();
            vector<Ponto> fecho(2 * n);
            int k = 0;

            for (int j = 0; j < n; j++) {
                while (k >= 2 &&
                       orientacao(fecho[k - 2], fecho[k - 1], pontos[j]) <= 0) {
                    k--;
                }

                fecho[k++] = pontos[j];
            }

            int limite = k + 1;

            for (int j = n - 2; j >= 0; j--) {
                while (k >= limite &&
                       orientacao(fecho[k - 2], fecho[k - 1], pontos[j]) <= 0) {
                    k--;
                }

                fecho[k++] = pontos[j];
            }

            k--;

            if (k != 4)
                continue;

            long long area = 0;

            for (int j = 0; j < k; j++) {
                int prox = (j + 1) % k;

                area += fecho[j].x * fecho[prox].y
                      - fecho[j].y * fecho[prox].x;
            }

            maior = max(maior, abs(area));
        }

        cout << maior / 2 << endl;
    }

    return 0;
}
