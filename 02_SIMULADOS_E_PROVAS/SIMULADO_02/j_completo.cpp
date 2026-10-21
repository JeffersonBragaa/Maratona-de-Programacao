#include <bits/stdc++.h>
using namespace std;

// ---------- busca em profundidade (só alcança quem) ----------
void dfs(int origem, vector<vector<int>> &ruas, vector<int> &vis)
{
    stack<int> pilha;

    pilha.push(origem);

    while (!pilha.empty())
    {
        int u = pilha.top();
        pilha.pop();

        if (vis[u])
            continue;

        vis[u] = 1;

        for (int i = 0; i < ruas[u].size(); i++)
        {
            int vizinho = ruas[u][i];

            if (!vis[vizinho])
            {
                pilha.push(vizinho);
            }
        }
    }
}

void dfs_invertida(int origem, vector<vector<int>> &ruas_inverso, vector<int> &vis)
{
    stack<int> pilha;

    pilha.push(origem);

    while (!pilha.empty())
    {
        int u = pilha.top();
        pilha.pop();

        if (vis[u])
            continue;

        vis[u] = 1;

        for (int i = 0; i < ruas_inverso[u].size(); i++)
        {
            int vizinho = ruas_inverso[u][i];

            if (!vis[vizinho])
            {
                pilha.push(vizinho);
            }
        }
    }
}

// ---------- pontes (low / tin) ----------
// Aresta é ponte se, sem ela, o grafo SEM MÃO parte em dois.
// Aqui a rua é ponte quando low[v] > tin[u].
int timer_dfs;
bool tem_ponte_mao_unica;

void dfs_pontes(int u, int aresta_pai, vector<vector<pair<int, int>>> &adj,
                vector<int> &mao_unica, vector<int> &vis, vector<int> &tin, vector<int> &low)
{
    vis[u] = 1;
    tin[u] = low[u] = timer_dfs++;

    for (auto [v, id] : adj[u])
    {
        if (id == aresta_pai)
            continue; // não volta pela mesma rua

        if (vis[v])
        {
            // aresta de retorno: só abaixa o low
            low[u] = min(low[u], tin[v]);
        }
        else
        {
            dfs_pontes(v, id, adj, mao_unica, vis, tin, low);
            low[u] = min(low[u], low[v]);

            // se o filho não consegue "subir" até u ou acima, a rua é ponte
            if (low[v] > tin[u])
            {
                if (mao_unica[id])
                    tem_ponte_mao_unica = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, t, i;

    while (cin >> n >> m)
    {
        // vértices = cruzamentos = 1..n  →  tamanho n+1
        vector<vector<int>> ruas(n + 1);         // como está (com mão)
        vector<vector<int>> ruas_inverso(n + 1); // espelho (para o "-")
        vector<vector<int>> ruas_sem_mao(n + 1); // só para o "*"

        // grafo sem mão COM id da rua (para achar pontes)
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> mao_unica; // mao_unica[id] = 1 se a rua nasceu T==1

        vector<int> vis(n + 1, 0);

        for (i = 1; i <= m; i++)
        {
            cin >> a >> b >> t;

            // a primeira rua é interditada: não entra em grafo nenhum
            if (i == 1)
                continue;

            int id = (int)mao_unica.size();
            mao_unica.push_back(t == 1);

            // para pontes: uma rua = uma aresta (mesmo se mão dupla)
            adj[a].push_back({b, id});
            adj[b].push_back({a, id});

            if (t == 2)
            {
                // mão dupla: nos dois sentidos, e o espelho é ela mesma
                ruas[a].push_back(b), ruas[b].push_back(a);
                ruas_inverso[a].push_back(b), ruas_inverso[b].push_back(a);
                ruas_sem_mao[a].push_back(b), ruas_sem_mao[b].push_back(a);
            }
            else
            {
                // mão única: só a→b no normal; espelho é b→a
                ruas[a].push_back(b);
                ruas_inverso[b].push_back(a);
                ruas_sem_mao[a].push_back(b), ruas_sem_mao[b].push_back(a);
            }
        }

        // ---------- 1) já está tudo ligado nos dois sentidos? → "-" ----------
        dfs(1, ruas, vis);
        if (count(vis.begin(), vis.end(), 1) == n)
        {
            fill(vis.begin(), vis.end(), 0);
            dfs_invertida(1, ruas_inverso, vis);

            if (count(vis.begin(), vis.end(), 1) == n)
            {
                cout << "-\n";
                continue;
            }
        }

        // ---------- 2) sem olhar a mão, a cidade está ligada? senão "*" ----------
        fill(vis.begin(), vis.end(), 0);
        dfs(1, ruas_sem_mao, vis);

        if (count(vis.begin(), vis.end(), 1) != n)
        {
            cout << "*\n";
            continue;
        }

        // ---------- 3) existe ponte de mão única? ----------
        //    sim  → precisa converter  → "2"
        //    não  → só inverter basta  → "1"
        fill(vis.begin(), vis.end(), 0);
        vector<int> tin(n + 1, -1), low(n + 1, -1);
        timer_dfs = 0;
        tem_ponte_mao_unica = false;

        for (int v = 1; v <= n; v++)
        {
            if (!vis[v])
                dfs_pontes(v, -1, adj, mao_unica, vis, tin, low);
        }

        if (tem_ponte_mao_unica)
            cout << "2\n";
        else
            cout << "1\n";
    }

    return 0;
}
