#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, t, i, x, atinge = 0;

    cin >> n;

    while (n--)
    {

        cin >> t;
        vector<int> v;
        string jogador;
        for (i = 0; i < t; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        cin >> jogador;

        for (i = 0; i < t; i++)
        {

            if (jogador[i] == 'J')
            {
                if (v[i] > 2)
                {
                    atinge++;
                }
            }
            else
            {
                if (v[i] < 3)
                {
                    atinge++;
                }
            }
        }

        cout << atinge << "\n";

        atinge = 0;
    }
    return 0;
}