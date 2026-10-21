#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, d, i, x, d_temp;

    cin >> n >> d;

    while (n || d)
    {
        vector<int> alu(n + 1, 0);
        d_temp = d;
        while (d--)
        {
            for (i = 1; i <= n; i++)
            {
                cin >> x;

                if (x == 1)
                {
                    alu[i]++;
                }
            }
        }

        if (count(alu.begin(), alu.end(), d_temp) > 0)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
        cin >> n >> d;
    }

    return 0;
}