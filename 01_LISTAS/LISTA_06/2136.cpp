#include <bits/stdc++.h>
using namespace std;

int main()
{
    string nome, es, vencedor;
    size_t maior = 0;
    set<string> sim, nao; 
    while (cin >> nome && nome != "FIM")
    {
        cin >> es;

        if (es == "YES")
        {

            if (sim.insert(nome).second && nome.size() > maior)
            {
                maior = nome.size();
                vencedor = nome;
            }
        }
        else
        {
            nao.insert(nome);
        }
    }

    for (const string &s : sim)
        cout << s << "\n";
    for (const string &s : nao)
        cout << s << "\n";

    cout << "\nAmigo do Habay:\n"
         << vencedor << "\n";
    return 0;
}