
#include <bits/stdc++.h>
using namespace std;

struct Segmento {
    long long x1, y1, x2, y2;
};

struct Evento {
    int x, tipo, id;
};

vector<Segmento> segmentos;
long long atualX;

struct Comparar {
    bool operator()(int a, int b) const {
        if (a == b)
            return false;

        Segmento p = segmentos[a];
        Segmento q = segmentos[b];

        long long dx1 = p.x2 - p.x1;
        long long dx2 = q.x2 - q.x1;

        long long y1 = p.y1 * dx1 + (p.y2 - p.y1) * (atualX - p.x1);
        long long y2 = q.y1 * dx2 + (q.y2 - q.y1) * (atualX - q.x1);

        long long v1 = y1 * dx2;
        long long v2 = y2 * dx1;

        if (v1 != v2)
            return v1 < v2;

        return a < b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;

    while (cin >> N >> C) {
        segmentos.resize(N);

        vector<Evento> eventos;
        vector<int> acima(N, -1);
        vector<int> consultas(C);
        vector<int> primeiro(C, -1);

        for (int i = 0; i < N; i++) {
            Segmento &s = segmentos[i];

            cin >> s.x1 >> s.y1 >> s.x2 >> s.y2;

            if (s.x1 > s.x2) {
                swap(s.x1, s.x2);
                swap(s.y1, s.y2);
            }

            eventos.push_back({(int)s.x1, 0, i});
            eventos.push_back({(int)s.x2, 2, i});
        }

        for (int i = 0; i < C; i++) {
            cin >> consultas[i];
            eventos.push_back({consultas[i], 1, i});
        }

        sort(eventos.begin(), eventos.end(),
            [](Evento a, Evento b) {
                if (a.x != b.x)
                    return a.x < b.x;

                return a.tipo < b.tipo;
            });

        set<int, Comparar> ativos;

        for (Evento e : eventos) {
            atualX = e.x;

            if (e.tipo == 0) {
                auto it = ativos.insert(e.id).first;

                if (segmentos[e.id].y1 > segmentos[e.id].y2) {
                    auto proximo = next(it);

                    if (proximo != ativos.end())
                        acima[e.id] = *proximo;
                }
            }
            else if (e.tipo == 2) {
                auto it = ativos.find(e.id);

                if (segmentos[e.id].y2 > segmentos[e.id].y1) {
                    auto proximo = next(it);

                    if (proximo != ativos.end())
                        acima[e.id] = *proximo;
                }

                ativos.erase(it);
            }
            else {
                if (!ativos.empty())
                    primeiro[e.id] = *ativos.begin();
            }
        }

        vector<int> ordem(N);

        iota(ordem.begin(), ordem.end(), 0);

        sort(ordem.begin(), ordem.end(),
            [](int a, int b) {
                return max(segmentos[a].y1, segmentos[a].y2) >
                       max(segmentos[b].y1, segmentos[b].y2);
            });

        vector<long long> respostaX(N);
        vector<long long> respostaY(N);

        for (int i : ordem) {
            Segmento s = segmentos[i];

            if (s.y1 == s.y2) {
                respostaY[i] = s.y1;
                continue;
            }

            long long xAlto = (s.y1 > s.y2) ? s.x1 : s.x2;
            int j = acima[i];

            if (j == -1) {
                respostaX[i] = xAlto;
                respostaY[i] = -1;
            }
            else if (segmentos[j].y1 == segmentos[j].y2) {
                respostaX[i] = xAlto;
                respostaY[i] = segmentos[j].y1;
            }
            else {
                respostaX[i] = respostaX[j];
                respostaY[i] = respostaY[j];
            }
        }

        for (int i = 0; i < C; i++) {
            int j = primeiro[i];

            if (j == -1) {
                cout << consultas[i] << '\n';
            }
            else if (segmentos[j].y1 == segmentos[j].y2) {
                cout << consultas[i] << " " << segmentos[j].y1 << '\n';
            }
            else if (respostaY[j] == -1) {
                cout << respostaX[j] << '\n';
            }
            else {
                cout << respostaX[j] << " " << respostaY[j] << '\n';
            }
        }
    }

    return 0;
}
