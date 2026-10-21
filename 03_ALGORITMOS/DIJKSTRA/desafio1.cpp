#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3fLL

vector<vector<pair<int, long long int>>> adj;
vector<long long int> dist, pred, visitado;
priority_queue<pair<long long int, int>> q;

void dijkstra(int s)
{
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty())
    {
        int oo = q.top().second;
        q.pop();

        if (visitado[oo])
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

void imprime(int n)
{
    int atual = n;
    vector<int> p;
    if (dist[atual] == INF)
    {
        cout << "-1\n";
    }
    else
    {
        p.push_back(atual);
        while (atual != 1)
        {
            atual = pred[atual];
            p.push_back(atual);
        }

        for (int i = p.size() - 1; i >= 0; i--)
        {

            if (i == 0)
            {
                cout << p[i];
            }else{
                cout << p[i] << " ";
            }
        }

        cout << "\n";
    }
}

int main()
{
    int n, m;

    cin >> n >> m;

    int total = n + 1; // pilares 0, 1, ..., n+1

    adj.assign(total, {});
    dist.assign(total, INF);
    pred.assign(total, -1);
    visitado.assign(total, 0);

    while (m--)
    {
        long long int w;
        int a, b;

        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dijkstra(1);

    imprime(n);

    return 0;
}