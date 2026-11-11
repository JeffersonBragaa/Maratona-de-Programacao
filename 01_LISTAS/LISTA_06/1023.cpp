
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y, media, k = 1;
    long long soma, casas;

    bool primeiroCaso = true;

    while (cin >> n && n != 0)
    {
        vector<pair<int, int>> v;

        soma = 0;
        casas = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;

            media = y / x;

            casas += x;
            soma += y;

            v.push_back({x, media});
        }

        sort(v.begin(), v.end(), [](auto a, auto b)
        {
            return a.second < b.second;
        });

        if (!primeiroCaso)
            cout << '\n';

        primeiroCaso = false;

        cout << "Cidade# " << k++ << ":\n";

        bool primeiro = true;

        for (int i = 0; i < v.size();)
        {
            int moradores = v[i].first;
            int consumo = v[i].second;

            i++;

            while (i < v.size() && v[i].second == consumo)
            {
                moradores += v[i].first;
                i++;
            }

            if (!primeiro)
                cout << " ";

            primeiro = false;

            cout << moradores << "-" << consumo;
        }

        double cm = (double)soma / casas;
        cm = floor(cm * 100) / 100;

        printf("\nConsumo medio: %.2f m3.\n", cm);
    }

    return 0;
}
