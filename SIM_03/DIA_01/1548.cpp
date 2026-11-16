#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m, i, x;

    cin >> n;

    while (n--)
    {
        int cont = 0;
        vector<int> fila;
        vector<int> aux;
        cin >> m;

        for (i = 0; i < m; i++)
        {
            cin >> x;

            fila.push_back(x);
            aux.push_back(x);
        }

        sort(fila.rbegin(), fila.rend());

        for(i = 0; i < aux.size(); i++){

            if(aux[i] == fila[i]) cont++;
        }

        cout << cont << endl;
    }
    return 0;
}