#include <bits/stdc++.h>
using namespace std;

int main() {
    int g, p, i, j, k, s, sp;

    cin >> g >> p;

    while (g != 0 || p != 0) {

        vector<vector<int>> gp(g, vector<int>(p));

        for (i = 0; i < g; i++) {
            for (j = 0; j < p; j++) {
                cin >> gp[i][j];
            }
        }

        cin >> s;

        vector<vector<int>> pontuacao(s);

        for (i = 0; i < s; i++) {
            cin >> sp;

            pontuacao[i].resize(sp);

            for (j = 0; j < sp; j++) {
                cin >> pontuacao[i][j];
            }
        }

        for (i = 0; i < s; i++) {

            vector<int> pi(p + 1, 0);

            for (k = 0; k < g; k++) {
                for (j = 0; j < p; j++) {

                    int pos = gp[k][j];

                    if (pos <= (int)pontuacao[i].size()) {
                        pi[j + 1] += pontuacao[i][pos - 1];
                    }
                }
            }

            int maior = 0;

            for (j = 1; j <= p; j++) {
                if (pi[j] > maior) {
                    maior = pi[j];
                }
            }

            bool primeiro = true;

            for (j = 1; j <= p; j++) {
                if (pi[j] == maior) {
                    if (!primeiro) {
                        cout << " ";
                    }

                    cout << j;
                    primeiro = false;
                }
            }

            cout << "\n";
        }

        cin >> g >> p;
    }

    return 0;
}