// Par de pontos mais proximos: MP1, Aula 11, slides 31 a 37.
// Estrutura e nomes de variaveis preservados do PDF.
// ATENCAO: dentro de resolver, d, dE e dD sao distancias AO QUADRADO.
// No painel C++ do HTML, os nomes equivalentes sao d2, dE2 e dD2.
// Coordenadas devem respeitar limites que evitem overflow em long long.

#include <bits/stdc++.h>
using namespace std;

// Slide 31: representacao do ponto e distancia ao quadrado.
struct Ponto {
    long long x, y;
};

long long dist2(const Ponto& a, const Ponto& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// Slide 32: criterios de ordenacao.
bool porX(const Ponto& a, const Ponto& b) {
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

bool porY(const Ponto& a, const Ponto& b) {
    if (a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}

// Entrada: intervalo [ini, fim) ordenado por X.
// Saida: menor distancia ao quadrado e intervalo ordenado por Y.
long long resolver(vector<Ponto>& P, int ini, int fim,
                   vector<Ponto>& aux) {
    // Slide 33: caso base.
    int n = fim - ini;
    if (n <= 3) {
        long long d = LLONG_MAX;
        for (int i = ini; i < fim; ++i)
            for (int j = i + 1; j < fim; ++j)
                d = min(d, dist2(P[i], P[j]));
        sort(P.begin() + ini, P.begin() + fim, porY);
        return d;
    }

    // Salve a divisoria antes que as chamadas reordenem P por Y.
    int meio = (ini + fim) / 2;
    long long xMeio = P[meio].x;

    // Slide 34: resolver as metades e intercalar a ordem por Y.
    long long dE = resolver(P, ini, meio, aux);
    long long dD = resolver(P, meio, fim, aux);
    long long d = min(dE, dD);

    merge(P.begin() + ini, P.begin() + meio,
          P.begin() + meio, P.begin() + fim,
          aux.begin() + ini, porY);
    copy(aux.begin() + ini, aux.begin() + fim,
         P.begin() + ini);

    // Slide 35: construir a faixa. Aqui d representa d².
    vector<Ponto> faixa;
    for (int i = ini; i < fim; ++i) {
        long long dx = P[i].x - xMeio;
        if (dx * dx < d)
            faixa.push_back(P[i]);
    }

    // A faixa ja esta ordenada por Y.
    // Slide 36: ate sete seguintes, interrompendo pelo corte em Y.
    for (int i = 0; i < (int)faixa.size(); ++i) {
        for (int j = i + 1;
             j < (int)faixa.size() && j <= i + 7; ++j) {
            long long dy = faixa[j].y - faixa[i].y;
            if (dy * dy >= d)
                break;
            d = min(d, dist2(faixa[i], faixa[j]));
        }
    }
    return d;
}

// Slide 37: mesmos pontos da aula e do conjunto inicial do HTML.
int main() {
    vector<Ponto> P = {
        {-2, -1}, {0, 3}, {1, -2},
        {3, 4}, {4, 2}
    };
    if (P.size() < 2)
        return 0;

    sort(P.begin(), P.end(), porX);
    vector<Ponto> aux(P.size());
    long long d2 = resolver(P, 0, (int)P.size(), aux);
    cout << "Distancia ao quadrado: " << d2 << '\n';
    cout << "Distancia: " << sqrt((long double)d2) << '\n';
}
