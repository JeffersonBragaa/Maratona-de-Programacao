#include <bits/stdc++.h>
using namespace std;

int main()
{
    string expre;

    while (getline(cin, expre))
    {
        stack<char> p;
        int posicao = 1;
        int erro = 0;
        int tamanho = expre.size();

        for (int i = 0; i < tamanho; i++, posicao++)
        {
            char x = expre[i];
            char esperado = '\0';

            if (x == '(' && i + 1 < tamanho && expre[i + 1] == '*')
            {
                p.push('*');
                i++;
                continue;
            }

            if (x == '*' && i + 1 < tamanho && expre[i + 1] == ')')
            {
                esperado = '*';
                i++;
            }
            else if (x == '(' || x == '[' || x == '{' || x == '<')
            {
                p.push(x);
                continue;
            }
            else if (x == ')')
                esperado = '(';
            else if (x == ']')
                esperado = '[';
            else if (x == '}')
                esperado = '{';
            else if (x == '>')
                esperado = '<';

            if (esperado == '\0')
                continue;

            if (p.empty() || p.top() != esperado)
            {
                erro = posicao;
                break;
            }

            p.pop();
        }

        if (erro == 0 && !p.empty())
            erro = posicao;

        if (erro == 0)
            cout << "YES\n";
        else
            cout << "NO " << erro << '\n';
    }

    return 0;
}