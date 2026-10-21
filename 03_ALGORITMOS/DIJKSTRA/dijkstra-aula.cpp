#include <bits/stdc++.h>
using namespace std;

// Definicoes gerais (slide 62)
#define INF 0x3f3f3f3f // infinito

int N = 9; // numero de vertices do grafo

vector<int> dist(N, INF);                    // vetor de distancias
vector<int> pred(N, -1);                     // vetor de predecessores
vector<int> visitado(N, 0);                  // marca se o vertice foi visitado
priority_queue<pair<int, int>> q;            // fila: (distancia, vertice)
vector<vector<pair<int, int>>> adj(N);       // lista de adjacencia: adj[a] = (vizinho, peso)

// Dijkstra (slide 63): recebe o vertice de origem
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
            int b = u.first;
            int w = u.second;

            if(dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                pred[b] = a;
                q.push( {-dist[b], b} );
            }
        } // for
    } // while
} // dijkstra

int main()
{
    // Grafo do slide 21: cada linha e um vertice com seus (vizinho, peso)
    adj[0] = { {1, 4}, {6, 7} };
    adj[1] = { {0, 4}, {2, 9}, {6, 11}, {7, 20} };
    adj[2] = { {1, 9}, {3, 6}, {4, 2} };
    adj[3] = { {2, 6}, {4, 10}, {5, 5} };
    adj[4] = { {2, 2}, {3, 10}, {5, 15}, {7, 1}, {8, 5} };
    adj[5] = { {3, 5}, {4, 15}, {8, 12} };
    adj[6] = { {0, 7}, {1, 11}, {7, 1} };
    adj[7] = { {1, 20}, {4, 1}, {6, 1}, {8, 3} };
    adj[8] = { {4, 5}, {5, 12}, {7, 3} };

    int s = 0; // origem
    int t = 5; // destino

    dijkstra(s);

    // Resultado: tabela Nó / Dist / Pred (como no slide 61)
    for(int v = 0; v < N; v++)
        printf("%d: dist = %d, pred = %d\n", v, dist[v], pred[v]);

    // Rota: a partir do destino, segue os predecessores ate a origem (slide 61)
    printf("Rota de %d ate %d (de tras para frente):", s, t);
    for(int v = t; v != -1; v = pred[v])
        printf(" %d", v);
    printf("\n");

    return 0;
}