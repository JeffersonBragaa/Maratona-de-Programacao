#include <bits/stdc++.h>

using namespace std;

int main()
{

    int m, n, i, x, c_atual, f_atual, temp;

    cin >> n >> m;

    vector<int> func(n);
    vector<int> cli(m);
    vector<int> tempo(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> func[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> cli[i];
    }

    for (int j = 0; j < m; j++)
    {

        int menor = tempo[0];
        int indice = 0;

        for (int i = 1; i < n; i++)
        {
            if (tempo[i] < menor)
            {
                menor = tempo[i];
                indice = i;
            }
        }

        tempo[indice] += func[indice] * cli[j];
    }

    int resposta = tempo[0];

    for (int i = 1; i < n; i++)
    {
        if (tempo[i] > resposta)
        {
            resposta = tempo[i];
        }
    }

    cout << resposta << "\n";

    return 0;
}