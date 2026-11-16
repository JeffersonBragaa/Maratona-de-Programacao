// solve(x) retorna a menor quantidade de moedas para formar x, ou INF se impossível.
// A memoização resolve restos recursivamente e guarda respostas para reutilizar.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX = 10001;
constexpr int INF = 1000000000;
int solve (int x, const vector<int>& coins, vector<int>& ready, vector<int>& value)
{
   // Restante negativo torna a escolha impossível; INF impede que ela seja a melhor.
   if (x < 0) return INF;
   // Restante zero encerra este caminho: nenhuma outra moeda é necessária.
   if (x == 0) return 0;
   // ready[x] indica resposta pronta; value[x] guarda a quantidade de moedas.
   // Observe: um acerto no cache retorna aqui, sem repetir o laço nem a recursão.
   if (ready[x]) return value[x];
   // Cada chamada tem seu próprio best; INF inicia a busca sem solução conhecida.
   int best = INF;
   // Cada moeda abre uma tentativa para o restante desta chamada.
   for (auto c : coins) {
     // solve(x-c) resolve o valor restante; +1 conta a moeda escolhida agora.
     // Este for espera a recursão retornar; só então min compara o total com best.
     // No debug, acompanhe o best da chamada atual: ele pode melhorar no retorno.
     // Com coins = {1, 3, 4}, x = 6 e c = 3: o restante é 3, que exige 1 moeda.
     // Esse 1 retornado + a moeda atual dá 2 moedas; restante 3 não é quantidade.
     best = min (best, solve(x-c, coins, ready, value)+1);
   }
   // Após testar todas as moedas, marca a resposta pronta e preenche o cache.
   // Avance esta linha no debug para ver ready[x] e value[x] receberem o resultado.
   ready[x] = true; value[x] = best;
   // Devolve a quantidade ao chamador, que retoma a tentativa que estava esperando.
   return best;
}

int main()
{
    int x;
    if (!(cin >> x) || x < 0 || x >= MAX) return 1;
    // No debug, selecione main na pilha para acompanhar os vetores locais.
    const vector<int> coins = {1, 3, 4};
    vector<int> ready(x + 1, false);
    vector<int> value(x + 1, 0);
    // As referências permitem que solve atualize estes mesmos vetores.
    cout << solve(x, coins, ready, value) << '\n';
}
