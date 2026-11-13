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

double distancia(Ponto a, Ponto b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<Ponto> pontos(n);

        for (int i = 0; i < n; i++) {
            cin >> pontos[i].x >> pontos[i].y;
        }

        sort(pontos.begin(), pontos.end(), comparar);

        pontos.erase(unique(pontos.begin(), pontos.end(),
            [](Ponto a, Ponto b) {
                return a.x == b.x && a.y == b.y;
            }), pontos.end());

        n = pontos.size();

        if (n == 1) {
            cout << fixed << setprecision(2);
            cout << "Tera que comprar uma fita de tamanho 0.00." << endl;
            continue;
        }

        vector<Ponto> fecho(2 * n);
        int k = 0;

        for (int i = 0; i < n; i++) {
            while (k >= 2 && orientacao(fecho[k - 2], fecho[k - 1], pontos[i]) <= 0) {
                k--;
            }

            fecho[k++] = pontos[i];
        }

        int limite = k + 1;

        for (int i = n - 2; i >= 0; i--) {
            while (k >= limite && orientacao(fecho[k - 2], fecho[k - 1], pontos[i]) <= 0) {
                k--;
            }

            fecho[k++] = pontos[i];
        }

        k--;

        double total = 0;

        for (int i = 0; i < k; i++) {
            total += distancia(fecho[i], fecho[(i + 1) % k]);
        }

        cout << fixed << setprecision(2);
        cout << "Tera que comprar uma fita de tamanho " << total << "." << endl;
    }

    return 0;
}
