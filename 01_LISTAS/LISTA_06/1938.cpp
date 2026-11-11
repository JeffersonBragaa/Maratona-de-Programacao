
#include <bits/stdc++.h>
using namespace std;

void verifica(const vector<pair<int, int>>& vet, int i, long long &cont) {

    int y1 = vet[i].second;

    int menorAcima = INT_MAX;
    int maiorAbaixo = INT_MIN;

    for (int j = i + 1; j < vet.size(); j++) {

        int y2 = vet[j].second;

        if (y2 > y1) {
            if (menorAcima > y2) {
                cont++;
            }
        }
        else if (y2 < y1) {
            if (maiorAbaixo < y2) {
                cont++;
            }
        }

        if (y2 > y1) {
            menorAcima = min(menorAcima, y2);
        }
        else if (y2 < y1) {
            maiorAbaixo = max(maiorAbaixo, y2);
        }
    }
}

int main() {

    int n, x, y;
    long long cont = 0;

    vector<pair<int, int>> vet;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vet.push_back({x, y});
    }

    sort(vet.begin(), vet.end());

    for (int i = 0; i < n; i++) {
        verifica(vet, i, cont);
    }

    cout << cont << '\n';

    return 0;
}
