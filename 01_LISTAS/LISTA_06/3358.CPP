#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, i, cont = 0;
    char x;
    cin >> n;

    while (n--)
    {
        string nome;
        cin >> nome;
        cont = 0;
        for (i = 0; i < nome.size(); i++)
        {
            x = tolower(nome[i]);
            if (x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u')
            {
                cont++;

                if (cont == 3)
                {
                    cout << nome << " nao eh facil\n";
                    break;
                }
            }
            else
            {
                cont = 0;
            }
        }

        if (cont < 3)
        {
            cout << nome << " eh facil\n";
        }
    }

    return 0;
}