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

bool noSegmento(Ponto a, Ponto b, Ponto p) {
    return orientacao(a, b, p) == 0 &&
           min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<Ponto> pontos(n);

        for (int i = 0; i < n; i++) {
            cin >> pontos[i].x >> pontos[i].y;
        }

        int camadas = 0;

        while (pontos.size() >= 3) {
            sort(pontos.begin(), pontos.end(), comparar);

            pontos.erase(unique(pontos.begin(), pontos.end(),
                [](Ponto a, Ponto b) {
                    return a.x == b.x && a.y == b.y;
                }), pontos.end());

            n = pontos.size();

            if (n < 3)
                break;

            vector<Ponto> fecho(2 * n);
            int k = 0;

            for (int i = 0; i < n; i++) {
                while (k >= 2 &&
                       orientacao(fecho[k - 2], fecho[k - 1], pontos[i]) <= 0) {
                    k--;
                }

                fecho[k++] = pontos[i];
            }

            int limite = k + 1;

            for (int i = n - 2; i >= 0; i--) {
                while (k >= limite &&
                       orientacao(fecho[k - 2], fecho[k - 1], pontos[i]) <= 0) {
                    k--;
                }

                fecho[k++] = pontos[i];
            }

            k--;

            if (k < 3)
                break;

            vector<Ponto> restantes;

            for (Ponto p : pontos) {
                bool borda = false;

                for (int i = 0; i < k; i++) {
                    if (noSegmento(fecho[i], fecho[(i + 1) % k], p)) {
                        borda = true;
                        break;
                    }
                }

                if (!borda) {
                    restantes.push_back(p);
                }
            }

            pontos = restantes;
            camadas++;
        }

        if (camadas % 2 == 1) {
            cout << "Take this onion to the lab!" << endl;
        }
        else {
            cout << "Do not take this onion to the lab!" << endl;
        }
    }

    return 0;
}
