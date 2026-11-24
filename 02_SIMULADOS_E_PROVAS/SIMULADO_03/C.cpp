#include <bits/stdc++.h>

using namespace std;

int dfs(int s, vector<vector<int>> &grafo, vector<int> &visitado)
{
    stack<int> pilha;
    pilha.push(s);
    visitado[s] = 1;

    int total = 0;

    while (!pilha.empty())
    {
        int u = pilha.top();
        pilha.pop();
        total++;

        for (int vizinho : grafo[u])
        {
            if (!visitado[vizinho])
            {
                visitado[vizinho] = 1;
                pilha.push(vizinho);
            }
        }
    }

    return total;
}

bool ehLagarta(int n, int e, vector<vector<int>> &grafo)
{
    if (e != n - 1)
        return false;

    vector<int> visitado(n + 1, 0);
    if (dfs(1, grafo, visitado) != n)
        return false;

    for (int u = 1; u <= n; u++)
    {
        if (grafo[u].size() <= 1)
            continue;

        int vizinhosInternos = 0;

        for (int vizinho : grafo[u])
        {
            if (grafo[vizinho].size() > 1)
                vizinhosInternos++;
        }

        if (vizinhosInternos > 2)
            return false;
    }

    return true;
}

int main()
{
    int n, caso = 1;

    while (cin >> n && n != 0)
    {
        int e;
        cin >> e;

        vector<vector<int>> grafo(n + 1);

        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;

            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }

        cout << "Grafo " << caso << ": ";

        if (ehLagarta(n, e, grafo))
            cout << "SIM\n";
        else
            cout << "NAO\n";

        caso++;
    }

    return 0;
}