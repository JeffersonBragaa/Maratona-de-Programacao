#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, numero;
    int h = 1;

    while (cin >> a && a != "0") {

        cin >> numero;

        if (h > 1)
            cout << "\n";

        cout << "Instancia " << h << "\n";

        if (numero.find(a) != string::npos)
            cout << "verdadeira\n";
        else
            cout << "falsa\n";

        h++;
    }

    return 0;
}