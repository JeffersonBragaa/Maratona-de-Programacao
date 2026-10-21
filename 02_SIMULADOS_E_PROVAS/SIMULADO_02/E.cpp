#include <bits/stdc++.h>
using namespace std;

int A(int m, int n, int nivel = 0)
{

    int r;
    if (m == 0)
    {
        r = n + 1;
    }
    else if (n == 0)
    {
        r = A(m - 1, 1, nivel + 1);
    }
    else
    {
        int interno = A(m, n - 1, nivel + 1);
        r = A(m - 1, interno, nivel + 1);
    }
    return r;
}
int main()
{

    unordered_map<char, int> vall = {
        {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}, {'i', 8}, {'j', 9}, {'k', 0}, {'l', 1}, {'m', 2}, {'n', 3}, {'o', 4}, {'p', 5}, {'q', 6}, {'r', 7}, {'s', 8}, {'t', 9}, {'u', 0}, {'v', 1}, {'w', 2}, {'x', 3}, {'y', 4}, {'z', 5}};

    int n, i, j, k, sm1 = 0, sm2 = 0, temp1, temp2, atual, anterior;
    string p1, p2, temp;

    cin >> n;

    while (n != 0)
    {
        vector<pair<string, string>> par(n + 1);
        vector<float> pont(n + 1, 0);
        priority_queue<pair<int, int>> pq;

        for (i = 1; i <= n; i++)
        {
            cin >> p1 >> p2;

            par[i] = {p1, p2};

            temp = par[i].first;
            for (k = 0; k < temp.size(); k++)
            {
                sm1 += vall[temp[k]];
            }
            temp = par[i].second;
            for (k = 0; k < temp.size(); k++)
            {
                sm2 += vall[temp[k]];
            }
            temp1 = sm1 % 4;
            temp2 = sm2 % 4;

            pq.push({A(temp1, temp2), -i});

            sm1 = 0;
            sm2 = 0;
        }

        cout << "VENCEDOR: " << -pq.top().second;
        anterior = pq.top().first;
        pq.pop();

        while (!pq.empty())
        {
            atual = pq.top().first;
            if (atual != anterior)
                break;

            cout << " - " << -pq.top().second;
            pq.pop();
        }

        cout << endl;

        cin >> n;
    }

    return 0;
}