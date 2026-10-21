#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        vector<long long> notas(n);
        long long soma = 0;

        for (int i = 0; i < n; i++) {
            cin >> notas[i];
            soma += notas[i];
        }

        
        if (soma % n != 0) {
            cout << -1 << '\n';
            continue;
        }

        long long media = soma / n;
        long long movimentos = 0;

        for (int i = 0; i < n; i++) {
            if (notas[i] < media) {
                movimentos += media - notas[i];
            }
        }

        cout << movimentos + 1 << '\n';
    }

    return 0;
}

