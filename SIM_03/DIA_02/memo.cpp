// Memoização (top-down): solve(x) devolve o menor número de moedas para formar x.
// As moedas podem ser usadas quantas vezes forem necessárias.
// Fluxo: main lê o alvo e prepara o cache; solve desce recursivamente para
// valores menores, guarda cada resposta e a reutiliza nas próximas chamadas.
// Exemplo: para x = 6, a melhor resposta é 2 (moedas 3 + 3).
// Custo: O(x * quantidade de moedas) em tempo e O(x) em memória, incluindo a pilha.

#include <bits/stdc++.h>
using namespace std;

// INF marca uma escolha impossível; ready informa se value já foi calculado.
const int INF = 1000000000;

vector<int> moedas = {1, 3, 4};
vector<int> ready;
vector<int> value;

int solve(int x)
{
    // Uma moeda maior que o restante não serve; formar zero custa zero moedas.
    if (x < 0)
        return INF;

    if (x == 0)
        return 0;

    // Se este valor já foi resolvido, devolve a resposta guardada.
    if (ready[x])
        return value[x];

    // Testa cada moeda como primeira escolha: 1 moeda + melhor solução do restante.
    int best = INF;

    for (int i = 0; i < moedas.size(); i++)
    {
        int c = moedas[i];

        best = min(best, solve(x - c) + 1);
    }

    // Salva o resultado antes de voltar à chamada anterior.
    ready[x] = true;
    value[x] = best;

    return best;
}

int main()
{
    int x;
    cin >> x;

    // Reserva um estado para cada valor de 0 até x; nenhum foi calculado ainda.
    ready.assign(x + 1, false);
    value.assign(x + 1, 0);

    cout << solve(x) << endl;

    return 0;
}
