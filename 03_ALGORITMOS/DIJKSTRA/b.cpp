#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

vector<vector<pair<int, int>>> adj;
vector<int> dist, pred, visitado;
priority_queue<pair<int, int>> q;

void dijkstra(int s)
{
    dist[s] = 0;
    q.push( {0, s} );

    while(!q.empty())
    {
        int a = q.top().second;
        q.pop();

        if(visitado[a]) continue;

        visitado[a] = 1;

        for(auto u : adj[a])
        {
            int v = u.first;
            int l = u.second;

            if(dist[a] + l < dist[v])
            {
                dist[v] = dist[a] + l;
                pred[v] = a;
                q.push( {-dist[v], v} );
            }
        } // for
    } // while
} // dijkstra

int main()
{
    int n, m;

    cin >> n >> m;

    while(n || m)
    {
        int total = n + 2; // pilares 0, 1, ..., n+1

        adj.assign(total, {});
        dist.assign(total, INF);
        pred.assign(total, -1);
        visitado.assign(total, 0);

        while(m--)
        {
            int u, v, l;

            cin >> u >> v >> l;
            adj[u].push_back({v, l});
            adj[v].push_back({u, l});
        }

        dijkstra(0);

        cout << dist[n + 1] << "\n";

        cin >> n >> m;
    }

    return 0;
}