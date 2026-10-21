#include <bits/stdc++.h>
using namespace std;

int main()
{
    string mensagem, crib;
    cin >> mensagem >> crib;

    int n = mensagem.size();
    int m = crib.size();
    int total = 0;

    for (int inicio = 0; inicio + m <= n; inicio++)
    {
        bool possivel = true;

        for (int j = 0; j < m; j++)
        {
            if (mensagem[inicio + j] == crib[j])
            {
                possivel = false; 
                break;
            }
        }

        if (possivel)
            total++;
    }

    cout << total << "\n";

    return 0;
}