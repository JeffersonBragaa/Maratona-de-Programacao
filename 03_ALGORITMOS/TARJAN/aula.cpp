#include <bits/stdc++.h>
using namespace std;

// Definicoes gerais (slide 86)
#define UNVISITED -1

int dfsNumberCounter = 0, numSCC = 0;

vector<int> dfs_num, dfs_low, visited; // num sequencial, low-link, "esta na pilha"
stack<int> st;                         // pilha
vector<vector<int>> AL;                // lista de adjacencia do grafo

// Algoritmo de Tarjan (slides 88 e 89)
void tarjan(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter;
    dfsNumberCounter++;
    st.push(u);
    visited[u] = 1;

    for(auto v : AL[u])
    {
        if (dfs_num[v] == UNVISITED) tarjan(v);
        if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u])
    {
        ++numSCC;
        while(1)
        {
            int v = st.top(); st.pop(); visited[v] = 0;
            if(u == v) break;
        }
    }
}

int main()
{
    int n, m;

    cin >> n >> m;


    AL.assign(n, {});
    dfs_num.assign(n, UNVISITED);
    dfs_low.assign(n, 0);
    visited.assign(n, 0);

    while(m--)
    {
        int a, b;

        cin >> a >> b;
        AL[a].push_back(b);   // grafo DIRECIONADO: so a -> b
    }

    // dentro da funcao principal (slide 87)
    for(int u = 7; u < n; u++)
    {
        
        if(dfs_num[u] == UNVISITED)
        {
            tarjan(u);
        }
        if(u == n){
            u = 0;
        }
    }

    cout << "numSCC = " << numSCC << "\n";
    for(int u = 0; u < n; u++)
        cout << "no " << u << ": num = " << dfs_num[u] << ", low = " << dfs_low[u] << "\n";

    return 0;
}