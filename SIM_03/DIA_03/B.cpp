#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Definicoes gerais (slide 62)
#define INF 0x3f3f3f3f // infinito

// Dijkstra (slide 63): recebe o vertice de origem
void dijkstra(int s, vector<int> &dist, vector<int> &pred,
              vector<int> &visitado, priority_queue<pair<int, int>> &q,
              vector<vector<pair<int, int>>> &adj)
{
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();

        if (visitado[a])
            continue;

        visitado[a] = 1;

        for (auto u : adj[a])
        {
            int b = u.first;
            int w = u.second;

            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                pred[b] = a;
                q.push({-dist[b], b});
            }
        } // for
    } // while
} // dijkstra
int main()
{

    int n, m, u, v, l;

    while ((cin >> n >> m) && n || m)
    {
        vector<int> dist(n + 2, INF);              // vetor de distancias
        vector<int> pred(n + 2, -1);               // vetor de predecessores
        vector<int> visitado(n + 2, 0);            // marca se o vertice foi visitado
        priority_queue<pair<int, int>> q;          // fila: (distancia, vertice)
        vector<vector<pair<int, int>>> adj(n + 2); // lista de adjacencia: adj[a] = (vizinho, peso)

        while (m--)
        {
            cin >> u >> v >> l;
            adj[u].push_back({v, l});
            adj[v].push_back({u, l});
        }

        dijkstra(0, dist, pred, visitado, q, adj);

        if (visitado[n + 1] != 0)
        {
            cout << dist[n + 1] << endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}
