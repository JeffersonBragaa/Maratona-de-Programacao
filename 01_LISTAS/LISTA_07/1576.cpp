
#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, H, R;

    vector<pair<int, int>> eventos;

    while (cin >> L >> H >> R) {
        eventos.push_back({L, H});
        eventos.push_back({R, -H});
    }

    sort(eventos.begin(), eventos.end());

    multiset<int> alturas;
    alturas.insert(0);

    vector<int> resposta;

    int anterior = 0;
    int n = eventos.size();

    for (int i = 0; i < n;) {
        int x = eventos[i].first;

        while (i < n && eventos[i].first == x) {
            int h = eventos[i].second;

            if (h > 0) {
                alturas.insert(h);
            }
            else {
                auto it = alturas.find(-h);

                if (it != alturas.end()) {
                    alturas.erase(it);
                }
            }

            i++;
        }

        int atual = *alturas.rbegin();

        if (atual != anterior) {
            resposta.push_back(x);
            resposta.push_back(atual);

            anterior = atual;
        }
    }

    for (int i = 0; i < (int)resposta.size(); i++) {
        if (i > 0)
            cout << " ";

        cout << resposta[i];
    }

    cout << endl;

    return 0;
}
