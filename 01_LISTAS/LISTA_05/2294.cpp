#include <bits/stdc++.h>
using namespace std;

int M, N;

int bfs(vector<vector<int>> &grade, int si, int sj)
{
    vector<vector<int>> dist(N, vector<int>(M, -1));

    queue<pair<int, int>> fila;

    dist[si][sj] = 0;
    fila.push({si, sj});

    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};

    while (!fila.empty())
    {
        auto [i, j] = fila.front();
        fila.pop();

        if (grade[i][j] == 0)
            return dist[i][j];

        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (ni < 0 || ni >= N || nj < 0 || nj >= M)
                continue;

            if (grade[ni][nj] == 'G')
                continue;

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
    cin >> N >> M;

    vector<vector<int>> grade(N, vector<int>(M));

    int pi = -1, pj = -1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grade[i][j];

            if (grade[i][j] == 3)
            {
                pi = i;
                pj = j;
            }
        }
    }

    cout << bfs(grade, pi, pj) << '\n';

    return 0;
}