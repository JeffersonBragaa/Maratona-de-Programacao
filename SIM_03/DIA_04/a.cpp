#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t, i, x, y;

    cin >> n >> t;
    while (n || t)
    {
        bool vira = true;

        vector<int> cima(n);
        vector<int> baixo(n);
        vector<int> aux(n, 0);

        for (i = 0; i < n; i++)
        {
            cin >> cima[i];
        }

        for (i = 0; i < n; i++)
        {
            cin >> baixo[i];
        }

        while (t--)
        {
            cin >> x >> y;

            if (aux[x - 1] == 0)
                aux[x - 1] = 1;
            else
                aux[x - 1] = 0;

            if (y < n)
            {
                if (aux[y] == 0)
                    aux[y] = 1;
                else
                    aux[y] = 0;
            }
        }

        for (i = 0; i < n; i++)
        {
            if (aux[i] == 1)
            {
                vira = !vira;
            }

            if (vira)
            {
                cout << cima[i] << " ";
            }
            else
            {
                cout << baixo[i] << " ";
            }
        }

        cout << endl;

        cin >> n >> t;
    }

    return 0;
}