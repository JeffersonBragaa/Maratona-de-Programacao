
#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

vector<int> moedas = {1, 3, 4};

int solve(int x)
{
    vector<int> value(x + 1, INF);

    value[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < moedas.size(); j++)
        {
            int c = moedas[j];

            if (i - c >= 0)
            {
                value[i] = min(value[i],
                               value[i - c] + 1);
            }
        }
    }

    return value[x];
}

int main()
{
    int x;
    cin >> x;

    cout << solve(x) << endl;

    return 0;
}
