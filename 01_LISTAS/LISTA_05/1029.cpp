#include <bits/stdc++.h>
using namespace std;

void faz(int fb, vector<vector<int>> &ar)
{
    vector<int> valor(fb + 1);
    vector<int> chamadas(fb + 1);

    valor[0] = 0;
    valor[1] = 1;

    chamadas[0] = 0;
    chamadas[1] = 0;

    for (int i = 2; i <= fb; i++)
    {
        ar[i].push_back(i - 1);
        ar[i].push_back(i - 2);

        valor[i] = valor[i - 1] + valor[i - 2];
        chamadas[i] = chamadas[i - 1] + chamadas[i - 2] + 2;
    }

    cout << "fib(" << fb << ") = "
         << chamadas[fb] << " calls = "
         << valor[fb] << "\n";
}

int main()
{
    int n, fb;
    cin >> n;

    while (n--)
    {
        cin >> fb;

        vector<vector<int>> ar(fb + 1);
        faz(fb, ar);
    }

    return 0;
}