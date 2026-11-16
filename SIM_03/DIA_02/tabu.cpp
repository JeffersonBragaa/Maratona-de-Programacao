// solve(x) retorna a menor quantidade de moedas para formar x, ou INF se impossível.
// A tabulação preenche a tabela do zero até x, usando respostas já calculadas.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX = 10001;
constexpr int INF = 1000000000;
int solve (int x, const vector<int>& coins, vector<int>& value)
{
  // Formar zero exige zero moedas: esta base permite iniciar as outras respostas.
  value[0] = 0;
  // i cresce de 1 até x para que cada restante menor já tenha resposta na tabela.
  for (int i=1; i <= x; i++) {
    // Cada novo i começa sem solução conhecida; observe suas melhorias no debug.
    value[i]=INF;
    // Testa cada moeda para melhorar a resposta parcial do valor i.
    for (auto c : coins) {
      // Uma moeda maior que i deixaria índice negativo; só acesse restos válidos.
      if (i-c >= 0) {
        // value[i-c] já foi calculado; +1 conta a moeda escolhida nesta tentativa.
        // min compara esse total com value[i] e pode melhorar a resposta parcial.
        // Com coins = {1, 3, 4}, i = 6 e c = 3: o restante é 3 e value[3] é 1.
        // Esse 1 + a moeda atual dá 2 moedas; índice 3 é valor, não quantidade.
        // Avance a linha no debug e observe value[6] passar de 3 para 2.
        value[i] = min (value[i], value[i-c]+1);
      }
    }
  }
  // Todas as tentativas até x terminaram; a tabela contém a resposta do alvo.
  return value[x];
}

int main()
{
    int x;
    if (!(cin >> x) || x < 0 || x >= MAX) return 1;
    // No debug, selecione main na pilha para acompanhar os vetores locais.
    const vector<int> coins = {1, 3, 4};
    vector<int> value(x + 1, 0);
    // A referência permite que solve preencha esta mesma tabela.
    cout << solve(x, coins, value) << '\n';
}
