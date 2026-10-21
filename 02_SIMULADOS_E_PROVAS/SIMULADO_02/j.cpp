#include <bits/stdc++.h>
using namespace std;

int dfs(int s, vector<vector<int>> &grafo, vector<int> &vis, stack<int> &pilha, int n)
{
    int u, c = 0;

    vis.assign(n + 1, 0);
    pilha.push(s);

    while(!pilha.empty())
    {
        u = pilha.top();
        pilha.pop();

        if(!vis[u])
        {
            vis[u] = 1;
            c++;

            for(auto v : grafo[u])
                if(!vis[v])
                    pilha.push(v);
        }
    }
    return c;
}

void pontes(int u, int pai, vector<vector<pair<int, int>>> &ruas_sem_mao,
            vector<int> &unica, vector<int> &tin, vector<int> &low,
            int &tempo, bool &ponteUnica)
{
    tin[u] = low[u] = ++tempo;

    for(auto [v, id] : ruas_sem_mao[u])
    {
        if(id == pai) continue;

        if(tin[v]) low[u] = min(low[u], tin[v]);
        else
        {
            pontes(v, id, ruas_sem_mao, unica, tin, low, tempo, ponteUnica);
            low[u] = min(low[u], low[v]);

            if(low[v] > tin[u] && unica[id]) ponteUnica = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tempo, i, a, b, t;
    bool ponteUnica;

    vector<vector<int>> ruas, ruas_inverso;
    vector<vector<pair<int, int>>> ruas_sem_mao;
    vector<int> unica;
    vector<int> vis, tin, low;
    stack<int> pilha;

    while(cin >> n >> m)
    {
        ruas.assign(n + 1, {});
        ruas_inverso.assign(n + 1, {});
        ruas_sem_mao.assign(n + 1, {});
        unica.assign(m + 1, 0);
        tin.assign(n + 1, 0);
        low.assign(n + 1, 0);
        tempo = 0;
        ponteUnica = false;

        for(i = 1; i <= m; i++)
        {
            cin >> a >> b >> t;

            if(i == 1) continue;

            unica[i] = (t == 1);

            ruas_sem_mao[a].push_back({b, i});
            ruas_sem_mao[b].push_back({a, i});

            ruas[a].push_back(b);
            ruas_inverso[b].push_back(a);
            if(t == 2) ruas[b].push_back(a), ruas_inverso[a].push_back(b);
        }

        if(dfs(1, ruas, vis, pilha, n) == n && dfs(1, ruas_inverso, vis, pilha, n) == n)
        {
            cout << "-\n";
            continue;
        }

        pontes(1, 0, ruas_sem_mao, unica, tin, low, tempo, ponteUnica);
        if(tempo < n)
        {
            cout << "*\n";
            continue;
        }

        cout << (ponteUnica ? "2\n" : "1\n");
    }

    return 0;
}