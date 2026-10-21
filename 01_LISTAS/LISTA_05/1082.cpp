#include <bits/stdc++.h>

using namespace std;

void dfs(int s, int v, vector<vector<int>> &grafo,
         vector<int> &visitado, vector<int> &anterior,
         stack<int> &pilha)
{
    int u, i;
    string resposta;
    pilha.push(s);

    while (!pilha.empty())
    {
        u = pilha.top();
        pilha.pop();

        if (!visitado[u])
        {
            visitado[u] = 1;

            char p = u + 'a';
            resposta.push_back(p);

        }

        for (i = 0; i < grafo[u].size(); i++)
        {
            int vizinho = grafo[u][i];

            if (!visitado[vizinho])
            {
                pilha.push(vizinho);
                anterior[vizinho] = u;
            }
        }
    }
    sort(resposta.begin(), resposta.end());
    for(int i = 0; i < resposta.size(); i++){
        cout << resposta[i] << ",";
    }
    cout << "\n";
}

int main()
{
    int n, i, caso = 1;

    cin >> n;

    while (n--)
    {
        int v, e, cont = 0;
        char p;
        cin >> v >> e;

        vector<vector<int>> grafo(v);
        vector<int> visitado(v, 0);
        vector<int> anterior(v);
        stack<int> pilha;

        cout << "Case #" << caso << ":\n";

        while (e--)
        {
            char x, y;
            string resposta;
            cin >> x >> y;

            grafo[x - 'a'].push_back(y - 'a');
            grafo[y - 'a'].push_back(x - 'a');
        }

        for (i = 0; i < v; i++)
        {
            if (grafo[i].empty()){
                cont++;
                p = i + 'a';
                cout << p << ",\n";
                continue;
            }
            if (visitado[i] != 1)
            {
                cont++;

                dfs(i, v, grafo, visitado, anterior, pilha);
            }
        }
        cout << cont << " connected components\n";
        cout << "\n";

        cont = 0;
        caso++;
    }

    return 0;
}