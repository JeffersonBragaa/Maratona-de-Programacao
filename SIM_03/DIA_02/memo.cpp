
#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

vector<int> moedas = {1, 3, 4};
vector<int> ready;
vector<int> value;

int solve(int x)
{
    if (x < 0)
        return INF;

    if (x == 0)
        return 0;

    if (ready[x])
        return value[x];

    int best = INF;

    for (int i = 0; i < moedas.size(); i++)
    {
        int c = moedas[i];

        best = min(best, solve(x - c) + 1);
    }

    ready[x] = true;
    value[x] = best;

    return best;
}

int main()
{
    int x;
    cin >> x;

    ready.assign(x + 1, false);
    value.assign(x + 1, 0);

    cout << solve(x) << endl;

    return 0;
}
