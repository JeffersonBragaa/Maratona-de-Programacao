#include <bits/stdc++.h>

using namespace std;

void volume(double b, double bm, double h, double x, double &v)
{
    double r = b + (bm - b) * x / h;
    v = ((M_PI * x) / 3) * ((b * b) + (b * r) + (r * r));
}

int main()
{
    int c;
    double n, l, b, bm, h;
    double v, x;

    cin >> c;

    while (c--)
    {
        cin >> n >> l;
        cin >> b >> bm >> h;

        double alvo = l / n;
        double ini = 0, fim = h;

        for (int i = 0; i < 100; i++)
        {
            x = (ini + fim) / 2;
            volume(b, bm, h, x, v);

            if (v < alvo)
                ini = x;
            else
                fim = x;
        }

        printf("%.2f\n", ini);
    }

    return 0;
}