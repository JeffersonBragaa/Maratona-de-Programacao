#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        queue<int> fila;
        vector<int> descartadas;

        for (int i = 1; i <= n; i++) {
            fila.push(i);
        }

        while (fila.size() > 1) {
            descartadas.push_back(fila.front());
            fila.pop();

            fila.push(fila.front());
            fila.pop();
        }

        cout << "Discarded cards:";

        for (size_t i = 0; i < descartadas.size(); i++) {
            if (i == 0)
                cout << " " << descartadas[i];
            else
                cout << ", " << descartadas[i];
        }

        cout << "\n";
        cout << "Remaining card: " << fila.front() << "\n";
    }

    return 0;
}