#include <bits/stdc++.h>
using namespace std;

string soma(const string &a, const string &b)
{
    string resultado = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int valor = carry;

        if (i >= 0)
        {
            valor += a[i] - '0';
            i--;
        }
        if (j >= 0)
        {
            valor += b[j] - '0';
            j--;
        }

        int digito = valor % 10;
        resultado.push_back('0' + digito);
        carry = valor / 10;
    }

    reverse(resultado.begin(), resultado.end());
    return resultado;
}

bool maior(const string &a, const string &b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    return a > b;
}

int main()
{
    vector<string> fib = {"1", "2"};

    while (fib.back().size() <= 101)
    {
        string penultimo = fib[fib.size() - 2];
        string ultimo = fib[fib.size() - 1];

        string proximo = soma(ultimo, penultimo);

        fib.push_back(proximo);
    }

    string a, b;
    while (cin >> a >> b)
    {
        if (a == "0" && b == "0")
            break;

        int quantidade = 0;
        for (const string &f : fib)
        {
            if (maior(f, b))
                break;
            if (!maior(a, f))
                quantidade++;
        }
        cout << quantidade << '\n';
    }
    return 0;
}