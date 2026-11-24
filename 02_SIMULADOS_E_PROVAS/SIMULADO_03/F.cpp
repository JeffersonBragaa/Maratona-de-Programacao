#include <bits/stdc++.h>
using namespace std;

long long value[1000][1000];
long long sum[1001][1001];

int main()
{
    int l, c, m, n;

    while (cin >> l >> c >> m >> n && l != 0)
    {
        for (int y = 0; y < l; y++)
        {
            for (int x = 0; x < c; x++)
            {
                cin >> value[y][x];
            }
        }

        for (int y = 0; y < l; y++)
        {
            for (int x = 0; x < c; x++)
            {
                sum[y + 1][x + 1] = value[y][x] + sum[y][x + 1] + sum[y + 1][x] - sum[y][x];
            }
        }

        long long maior = LLONG_MIN;

        for (int y = 0; y + m <= l; y++)
        {
            for (int x = 0; x + n <= c; x++)
            {
                long long lote = sum[y + m][x + n] - sum[y][x + n] - sum[y + m][x] + sum[y][x];

                maior = max(maior, lote);
            }
        }

        cout << maior << '\n';
    }

    return 0;
}