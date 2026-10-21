#include <bits/stdc++.h>

using namespace std;

void dfsr(int u, vector<vector<int>> &grafo, vector<int> &visitado, int nivel)
{
    visitado[u] = 1;

    for (int v : grafo[u])
    {
        for (int i = 0; i < nivel; i++)
            cout << "  ";

        cout << u << "-" << v;

        if (!visitado[v])
        {
            cout << " pathR(G," << v << ")\n";
            dfsr(v, grafo, visitado, nivel + 1);
        }
        else
        {
            cout << "\n";
        }
    }
}

int main()
{
    int n, v, e, x, y;

    cin >> n;

    for (int cont = 1; cont <= n; cont++)
    {
        cin >> v >> e;

        vector<vector<int>> grafo(v);
        vector<int> visitado(v, 0);

        while (e--)
        {
            cin >> x >> y;
            grafo[x].push_back(y);
        }

        for (int i = 0; i < v; i++)
        {
            sort(grafo[i].begin(), grafo[i].end());
            grafo[i].erase(unique(grafo[i].begin(), grafo[i].end()), grafo[i].end());
        }

        cout << "Caso " << cont << ":\n";

        for (int i = 0; i < v; i++)
        {
            if (!grafo[i].empty() && !visitado[i])
            {
                dfsr(i, grafo, visitado, 1);
                cout << "\n";  
            }
        }
    }

    return 0;
}