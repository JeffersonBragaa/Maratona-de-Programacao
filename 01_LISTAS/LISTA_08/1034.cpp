#include <bits/stdc++.h>

using namespace std;

constexpr int fINF = 1000000;

// Tabulação (bottom-up)
// Retorna a menor quantidade de blocos necessária para formar m.
int solve(int m, const vector<int>& blocos, vector<int>& value)
{
    // Caso-base: para formar 0, precisamos de 0 blocos.
    value[0] = 0;

    // Calcula as respostas de 1 até m.
    for (int i = 1; i <= m; i++)
    {
        // Inicialmente, ainda não encontramos uma solução.
        value[i] = fINF;

        // Testa todos os tamanhos de blocos disponíveis.
        for (auto c : blocos)
        {
            // Evita acessar posições negativas do vetor.
            if (i - c >= 0)
            {
                // Compara a melhor resposta atual com:
                // 1 bloco escolhido + a melhor solução para o restante.
                value[i] = min(value[i], value[i - c] + 1);
            }
        }
    }

    // Retorna a menor quantidade de blocos para formar m.
    return value[m];
}

int main()
{
    int m, t, n, i;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        vector<int> blocos(n);
        vector<int> value(m + 1, 0);

        for (i = 0; i < n; i++)
        {
            cin >> blocos[i];
        }

        cout << solve(m, blocos, value) << '\n';
    }

    return 0;
}
