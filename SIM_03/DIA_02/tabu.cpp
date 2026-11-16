// Tabulação (bottom-up): value[i] é o menor número de moedas para formar i.
// As moedas podem ser usadas quantas vezes forem necessárias.
// Fluxo: main lê o alvo; solve começa no caso-base 0 e preenche 1, 2, ..., x.
// Ao calcular i, cada restante i - c já tem sua resposta na tabela.
// Exemplo: para x = 6, value[6] = 2 pelas moedas 3 + 3.
// Custo: O(x * quantidade de moedas) em tempo e O(x) em memória.

#include <bits/stdc++.h>
using namespace std;

// INF marca valores que ainda não têm uma combinação conhecida.
const int INF = 1000000000;

vector<int> moedas = {1, 3, 4};

int solve(int x)
{
    // Começa com todos os valores sem solução; formar zero usa zero moedas.
    vector<int> value(x + 1, INF);

    value[0] = 0;

    // Avança do menor alvo ao maior, garantindo que os restos já estejam prontos.
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < moedas.size(); j++)
        {
            int c = moedas[j];

            // Só consulta i - c quando o restante não é negativo.
            if (i - c >= 0)
            {
                // Compara a melhor resposta atual com usar c e resolver o restante.
                value[i] = min(value[i],
                               value[i - c] + 1);
            }
        }
    }

    // Entrega a resposta do alvo pedido na entrada.
    return value[x];
}

int main()
{
    int x;
    cin >> x;

    cout << solve(x) << endl;

    return 0;
}
