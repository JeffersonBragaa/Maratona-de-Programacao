#include <bits/stdc++.h>
using namespace std;

int bfs(vector<string> &grade, int N, int M, int si, int sj)
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

        if (grade[i][j] == 'S')
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    while (cin >> N >> M && (N != 0 || M != 0))
    {
        vector<string> grade(N);
        int pi = -1, pj = -1;

        for (int i = 0; i < N; i++)
        {
            cin >> grade[i];

            for (int j = 0; j < M; j++)
            {
                if (grade[i][j] == 'P')
                {
                    pi = i;
                    pj = j;
                }
            }
        }

        cout << bfs(grade, N, M, pi, pj) << '\n';
    }

    return 0;
}