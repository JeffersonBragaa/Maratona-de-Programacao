#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;
    bool valid = true;
    int cont = 0, maiu = 0, minu = 0;

    while (cin >> s)
    {
        if (s.size() > 5 && s.size() <= 32)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= '0' && s[i] <= '9'))
                {
                    valid = false;
                    break;
                }
                else if (s[i] >= '0' && s[i] <= '9')
                {
                    cont++;
                }
                else if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    maiu++;
                }
                else
                {
                    minu++;
                }
            }

            if (cont > 0 && maiu > 0 && minu > 0 && valid == true)
            {
                cout << "Senha valida.\n";
            }
            else
            {
                cout << "Senha invalida.\n";
            }
        }
        else
        {
            cout << "Senha invalida.\n";
        }

        valid = true;
        cont = 0;
        maiu = 0;
        minu = 0;
    }

    return 0;
}