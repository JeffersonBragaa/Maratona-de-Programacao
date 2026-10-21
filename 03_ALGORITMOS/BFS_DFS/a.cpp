#include <bits/stdc++.h>
using namespace std;

int M, N;

int bfs(vector<string>& grade, int si, int sj)
{
    vector<vector<int>> dist(M, vector<int>(N, -1));

    queue<pair<int, int>> fila;

    dist[si][sj] = 0;
    fila.push({si, sj});

    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};

    while (!fila.empty())
    {
        auto [i, j] = fila.front();
        fila.pop();

        // Encontrou a saída
        if (grade[i][j] == 'S')
            return dist[i][j];

        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];

            // Fora da matriz
            if (ni < 0 || ni >= M || nj < 0 || nj >= N)
                continue;

            // Câmara com guarda
            if (grade[ni][nj] == 'G')
                continue;

            // Já visitado
            if (dist[ni][nj] != -1)
                continue;

            dist[ni][nj] = dist[i][j] + 1;
            fila.push({ni, nj});
        }
    }

    return -1;
}

int main()
{
    cin >> M >> N;

    while (M != 0 && N != 0)
    {
        vector<string> grade(M);

        int pi, pj;

        // Lê a caverna
        for (int i = 0; i < M; i++)
        {
            cin >> grade[i];

            for (int j = 0; j < N; j++)
            {
                if (grade[i][j] == 'P')
                {
                    pi = i;
                    pj = j;
                }
            }
        }

        cout << bfs(grade, pi, pj) << '\n';

        cin >> M >> N;
    }

    return 0;
}