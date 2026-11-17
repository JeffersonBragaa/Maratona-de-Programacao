#include <bits/stdc++.h>
using namespace std;

// Aula 10: Union-Find Disjoint Sets (slides 36 a 38).

// Versao inicial do slide 36:
// A funcao findd() recebe um elemento X e retorna o representativo de X.
// int findd(int x, int link[])
// {
//     while (x != link[x]) x = link[x];
//     return x;
// }

// Versao com compressao de caminho apresentada no slide 38.
// A funcao findd() recebe um elemento X e retorna o representativo de X.
int findd(int x, vector<int> &link, vector<int> &sizee)
{
    return (x == link[x]) ? x : (link[x] = findd(link[x], link, sizee));
}

// A funcao same() verifica se os elementos A e B pertencem ao mesmo conjunto.
int same(int a, int b, vector<int> &link, vector<int> &sizee)
{
    return findd(a, link, sizee) == findd(b, link, sizee);
}

// A funcao unite() mescla os conjuntos que contem os elementos A e B
void unite(int a, int b, vector<int> &link, vector<int> &sizee)
{
    a = findd(a, link, sizee);
    b = findd(b, link, sizee);

    if (a == b)
        return; // A e B ja estao no mesmo conjunto

    if (sizee[a] < sizee[b])
        std::swap(a, b);

    sizee[a] += sizee[b];
    link[b] = a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q, i, x, y;
    bool first = true;

    while (cin >> n >> m >> q)
    {
        if (!first)
            cout << '\n'; // linha em branco só ENTRE os casos
        first = false;

        vector<int> link(n + 1);
        vector<int> sizee(n + 1, 1);

        for (i = 1; i <= n; i++)
        {
            link[i] = i;
        }

        while (m--)
        {
            cin >> x >> y;
            unite(x, y, link, sizee);
        }

        while (q--) // faltava este while
        {
            cin >> x >> y;

            if (same(x, y, link, sizee))
            {
                cout << "S\n";
            }
            else
            {
                cout << "N\n";
            }
        }
        // removido o cout << "\n" que ficava aqui
    }
}