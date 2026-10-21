#include <bits/stdc++.h>
using namespace std;

int mdc(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

void som(int n1, char s1, int d1, char s2, int n2, char s3, int d2)
{
    int r_n, r_d, r_mdc;

    if (s2 == '+')
    {
        r_n = (n1 * d2 + n2 * d1);
    }
    else
    {
        r_n = (n1 * d2 - n2 * d1);
    }
    r_d = (d1 * d2);

    r_mdc = mdc(r_n, r_d);

    cout << r_n << "/" << r_d << " = " << r_n / r_mdc << "/" << r_d / r_mdc << "\n";
}

void div_mult(int n1, char s1, int d1, char s2, int n2, char s3, int d2)
{
    int r_n, r_d, r_mdc;

    if (s2 == '*')
    {
        r_n = n1 * n2;
        r_d = d1 * d2;
    }
    else
    {
        r_n = n1 * d2;
        r_d = n2 * d1;
    }

    r_mdc = mdc(r_n, r_d);

    cout << r_n << "/" << r_d << " = " << r_n / r_mdc << "/" << r_d / r_mdc << "\n";
}

int main()
{
    char s1, s2, s3;
    int n, n1, d1, n2, d2;

    cin >> n;

    while (n--)
    {
        cin >> n1 >> s1 >> d1 >> s2 >> n2 >> s3 >> d2;

        if (s2 == '+' || s2 == '-')
        {
            som(n1, s1, d1, s2, n2, s3, d2);
        }
        else
        {
            div_mult(n1, s1, d1, s2, n2, s3, d2);
        }
    }

    return 0;
}