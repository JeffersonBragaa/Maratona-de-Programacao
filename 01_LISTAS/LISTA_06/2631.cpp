#include <bits/stdc++.h>

using namespace std;

int findd(int x, vector<int> &link);

int same(int a, int b, vector<int> &link)
{
    return findd(a, link) == findd(b, link);
}

void unite(int a, int b, vector<int> &link, vector<int> &sizee)
{
    a = findd(a, link);
    b = findd(b, link);

    if (a == b)
        return;

    if (sizee[a] < sizee[b])
        swap(a, b);

    sizee[a] += sizee[b];
    link[b] = a;
}

int findd(int x, vector<int> &link)
{
    return (x == link[x]) ? x : (link[x] = findd(link[x], link));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q, x, y, i;
    bool first = true;

    while (cin >> n >> m >> q)
    {
        if (!first)
            cout << '\n';
        first = false;

        vector<int> link(n + 1);
        vector<int> sizee(n + 1, 1);

        for (i = 1; i <= n; i++)
            link[i] = i;

        while (m--)
        {
            cin >> x >> y;
            unite(x, y, link, sizee);
        }

        while (q--)
        {
            cin >> x >> y;
            cout << (same(x, y, link) ? "S\n" : "N\n");
        }
    }

    return 0;
}