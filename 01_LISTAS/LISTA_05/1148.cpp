#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

void dijkstra(int s, int c, vector<vector<pair<int, int>>> &adj, vector<int> &dist, vector<int> &pred, vector<int> &visitado, priority_queue<pair<int, int>> &q)
{
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty())
    {
        int oo = q.top().second;

        q.pop();

        if (visitado[oo] == 1)
            continue;

        visitado[oo] = 1;

        for (auto u : adj[oo])
        {
            int b = u.first;
            int w = u.second;

            if (dist[oo] + w < dist[b])
            {
                dist[b] = dist[oo] + w;
                pred[b] = oo;
                q.push({-dist[b], b});
            }
        } // for
    } // while
} // dijkstra

int main()
{
    int n, e, x, y, h, k, o, d;

    cin >> n >> e;

    while (n || e)
    {

        int total = n + 1;

        vector<vector<pair<int, int>>> adj(total);
        vector<int> dist(total, INF), pred(total, -1), visitado(total, -1);
        priority_queue<pair<int, int>> q;

        while (e--)
        {
            cin >> x >> y >> h;
            adj[x].push_back({y, h});
        }

        for (int a = 1; a < total; a++)
            for (auto &p : adj[a])
                for (auto &r : adj[p.first])
                    if (r.first == a)
                    {
                        p.second = 0;
                        r.second = 0;
                    }

        cin >> k;

        while (k--)
        {
            cin >> o >> d;

            dist.assign(total, INF);
            pred.assign(total, -1);
            visitado.assign(total, -1);

            dijkstra(o, d, adj, dist, pred, visitado, q);
            if (visitado[d] == -1)
            {
                cout << "Nao e possivel entregar a carta\n";
            }
            else
            {
                cout << dist[d] << "\n";
            }
        }
        
        cout << "\n";
        
        cin >> n >> e;
    }

    return 0;
}