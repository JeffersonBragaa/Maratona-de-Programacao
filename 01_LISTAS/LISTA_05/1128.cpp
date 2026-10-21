#include <bits/stdc++.h>

using namespace std;

void dfs(int s, vector<vector<int>> &grafo, vector<int> &visitado)
{
    stack<int> pilha;
    pilha.push(s);
    visitado[s] = 1;

    while (!pilha.empty())
    {
        int u = pilha.top();
        pilha.pop();

        for (int vizinho : grafo[u])
        {
            if (!visitado[vizinho])
            {
                visitado[vizinho] = 1;
                pilha.push(vizinho);
            }
        }
    }
}

bool todosVisitados(vector<int> &visitado, int n)
{
    for (int i = 1; i <= n; i++)
        if (!visitado[i])
            return false;
    return true;
}

int main()
{
    int n, m;

    cin >> n >> m;
    while (n || m)
    {
        vector<vector<int>> grafo(n + 1);
        vector<vector<int>> invertido(n + 1);

        while (m--)
        {
            int v, w, p;
            cin >> v >> w >> p;

            if (p == 2)
            {
                grafo[v].push_back(w);
                grafo[w].push_back(v);
                invertido[v].push_back(w);
                invertido[w].push_back(v);
            }
            else
            {
                grafo[v].push_back(w);
                invertido[w].push_back(v);
            }
        }

        vector<int> visitado(n + 1, 0);
        dfs(1, grafo, visitado);
        bool vaiParaTodos = todosVisitados(visitado, n);

        fill(visitado.begin(), visitado.end(), 0);
        dfs(1, invertido, visitado);
        bool todosVoltam = todosVisitados(visitado, n);

        if (vaiParaTodos && todosVoltam)
            cout << "1\n";
        else
            cout << "0\n";

        cin >> n >> m;
    }

    return 0;
}