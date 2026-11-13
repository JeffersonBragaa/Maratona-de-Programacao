
#include <bits/stdc++.h>
using namespace std;

struct Ponto {
    double x, y;
};

double distancia2(Ponto a, Ponto b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return dx * dx + dy * dy;
}

bool compararX(Ponto a, Ponto b) {
    if (a.x != b.x)
        return a.x < b.x;

    return a.y < b.y;
}

bool compararY(Ponto a, Ponto b) {
    if (a.y != b.y)
        return a.y < b.y;

    return a.x < b.x;
}

double resolver(vector<Ponto>& p, int ini, int fim, vector<Ponto>& aux) {
    int n = fim - ini;

    if (n <= 3) {
        double menor = DBL_MAX;

        for (int i = ini; i < fim; i++) {
            for (int j = i + 1; j < fim; j++) {
                menor = min(menor, distancia2(p[i], p[j]));
            }
        }

        sort(p.begin() + ini, p.begin() + fim, compararY);

        return menor;
    }

    int meio = (ini + fim) / 2;
    double xMeio = p[meio].x;

    double esquerda = resolver(p, ini, meio, aux);
    double direita = resolver(p, meio, fim, aux);

    double menor = min(esquerda, direita);

    merge(
        p.begin() + ini, p.begin() + meio,
        p.begin() + meio, p.begin() + fim,
        aux.begin() + ini, compararY
    );

    copy(aux.begin() + ini, aux.begin() + fim, p.begin() + ini);

    vector<Ponto> faixa;

    for (int i = ini; i < fim; i++) {
        double dx = p[i].x - xMeio;

        if (dx * dx < menor) {
            faixa.push_back(p[i]);
        }
    }

    for (int i = 0; i < (int)faixa.size(); i++) {
        for (int j = i + 1; j < (int)faixa.size() && j <= i + 7; j++) {
            double dy = faixa[j].y - faixa[i].y;

            if (dy * dy >= menor)
                break;

            menor = min(menor, distancia2(faixa[i], faixa[j]));
        }
    }

    return menor;
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<Ponto> pontos(n);

        for (int i = 0; i < n; i++) {
            cin >> pontos[i].x >> pontos[i].y;
        }

        if (n < 2) {
            cout << "INFINITY" << endl;
            continue;
        }

        sort(pontos.begin(), pontos.end(), compararX);

        vector<Ponto> aux(n);

        double menor = resolver(pontos, 0, n, aux);

        if (menor >= 100000000.0) {
            cout << "INFINITY" << endl;
        }
        else {
            cout << fixed << setprecision(4);
            cout << sqrt(menor) << endl;
        }
    }

    return 0;
}
