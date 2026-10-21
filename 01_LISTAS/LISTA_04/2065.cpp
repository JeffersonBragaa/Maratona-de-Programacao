#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;

    cin >> n >> m;

    vector<int> func(n);
    vector<int> cli(m);
    vector<int> tempo(n, 0);

    // Tempo que cada funcionário leva por item
    for (int i = 0; i < n; i++) {
        cin >> func[i];
    }

    // Quantidade de itens de cada cliente
    for (int i = 0; i < m; i++) {
        cin >> cli[i];
    }

    // Processa cada cliente
    for (int j = 0; j < m; j++) {

        // Descobre quem ficará livre primeiro
        int menor = tempo[0];
        int indice = 0;

        for (int i = 1; i < n; i++) {
            if (tempo[i] < menor) {
                menor = tempo[i];
                indice = i;
            }
        }

        // Esse funcionário atende o cliente
        tempo[indice] += func[indice] * cli[j];
    }

    // O último funcionário a terminar determina o tempo total
    int resposta = tempo[0];

    for (int i = 1; i < n; i++) {
        if (tempo[i] > resposta) {
            resposta = tempo[i];
        }
    }

    cout << resposta << "\n";

    return 0;
}