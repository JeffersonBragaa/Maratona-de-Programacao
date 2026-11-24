#include <bits/stdc++.h>
using namespace std;

int M, N;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

bool bfs(const vector<string>& grade, vector<vector<int>>& grupo,
         vector<vector<int>>& grau, int si, int sj, int id)
{
    queue<pair<int, int>> fila;
    grupo[si][sj] = id;
    fila.push({si, sj});

    int total = 0;
    int pontas = 0;
    bool ramifica = false;

    while (!fila.empty())
    {
        auto [i, j] = fila.front();
        fila.pop();
        total++;

        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (ni < 0 || ni >= M || nj < 0 || nj >= N)
                continue;

            if (grade[ni][nj] != '1')
                continue;

            grau[i][j]++;

            if (grupo[ni][nj] != 0)
                continue;

            grupo[ni][nj] = id;
            fila.push({ni, nj});
        }

        if (grau[i][j] == 1)
            pontas++;

        if (grau[i][j] > 2)
            ramifica = true;
    }

    return total == 1 || (!ramifica && pontas == 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> M >> N && M != 0 && N != 0)
    {
        vector<string> grade(M);
        for (int i = 0; i < M; i++)
            cin >> grade[i];

        vector<vector<int>> grupo(M, vector<int>(N, 0));
        vector<vector<int>> grau(M, vector<int>(N, 0));
        vector<int> cobra(1, 0);

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grade[i][j] == '1' && grupo[i][j] == 0)
                {
                    int id = cobra.size();
                    cobra.push_back(bfs(grade, grupo, grau, i, j, id));
                }
            }
        }

        vector<int> prolongavel(cobra.size(), 0);

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grade[i][j] != '0')
                    continue;

                int vizinhos = 0;
                int pontas = 0;
                int ids[4], direcoes[4];

                for (int k = 0; k < 4; k++)
                {
                    int ni = i + di[k];
                    int nj = j + dj[k];

                    if (ni < 0 || ni >= M || nj < 0 || nj >= N)
                        continue;

                    int id = grupo[ni][nj];
                    if (id == 0)
                        continue;

                    vizinhos++;

                    if (cobra[id] && grau[ni][nj] <= 1)
                    {
                        ids[pontas] = id;
                        direcoes[pontas] = k;
                        pontas++;
                    }
                }

                if (vizinhos == 2 && pontas == 2 && ids[0] != ids[1]
                    && direcoes[0] / 2 == direcoes[1] / 2)
                {
                    prolongavel[ids[0]] = 1;
                    prolongavel[ids[1]] = 1;
                }
            }
        }

        int total = 0;

        for (int id = 1; id < (int)cobra.size(); id++)
        {
            if (cobra[id] && !prolongavel[id])
                total++;
        }

        cout << total << '\n';
    }

    return 0;
}