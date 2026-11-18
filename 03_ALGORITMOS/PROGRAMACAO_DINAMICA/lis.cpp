#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> array(n), length(n);

    for (int i=0; i<n; i++)
        cin >> array[i];

    int resposta = 0;

    for (int k=0; k<n; k++) {
        // O elemento atual sozinho forma uma subsequência.
        length[k] = 1;

        // Examina as posições anteriores a k.
        for (int i=0; i<k; i++) {
            if (array[i] < array[k]) {
                // Prolonga a sequência de i e mantém o melhor comprimento.
                length[k] = max (length[k], length[i]+1);
            }
        }

        // Guarda o maior comprimento entre todos os finais.
        resposta = max(resposta, length[k]);
    }

    cout << resposta << '\n';

    return 0;
}
