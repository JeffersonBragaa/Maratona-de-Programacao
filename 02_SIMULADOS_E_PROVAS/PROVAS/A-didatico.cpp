#include <bits/stdc++.h>

using namespace std;

// ===== AS 3 FUNCOES BASE DA AULA (nao mudam) =====
int findd(int x, vector<int> &link)
{
    return (x == link[x]) ? x : (link[x] = findd(link[x], link));
}

int same(int a, int b, vector<int> &link)
{
    return findd(a, link) == findd(b, link);
}

void unite(int a, int b, vector<int> &link, vector<int> &sizee)
{
    a = findd(a, link);
    b = findd(b, link);
    if (a == b)
        return;
    if (sizee[a] < sizee[b])
        swap(a, b);
    sizee[a] += sizee[b];
    link[b] = a;
}

int main()
{
    int n, c, x, y, a, b, ea, eb, r;

    cin >> n;

    vector<int> link(n + 1), sizee(n + 1, 1);
    vector<int> inimigo(n + 1, -1); // inimigo[RAIZ] = alguem do conjunto inimigo (ou -1)
    for (int i = 0; i <= n; i++)
        link[i] = i;

    cin >> c >> x >> y;
    while (c || x || y)
    {
        a = findd(x, link); // raiz de x
        b = findd(y, link); // raiz de y
        ea = inimigo[a];    // inimigo do conjunto de x
        eb = inimigo[b];    // inimigo do conjunto de y

        if (c == 1) // quer ser amigo
        {
            if (a == b)
            {
                // ja sao amigos, nao faz nada
            }
            else if (ea != -1 && findd(ea, link) == b)
            {
                cout << "-1\n"; // sao inimigos, nao pode ser amigo
            }
            else
            {
                unite(a, b, link, sizee);
                r = findd(a, link); // nova raiz
                if (ea != -1 && eb != -1)
                    unite(ea, eb, link, sizee); // inimigo em comum vira amigo
                if (ea == -1)
                    ea = eb; // ea passa a ser "o inimigo que existir"
                if (ea != -1)
                {
                    ea = findd(ea, link);
                    inimigo[r] = ea;
                    inimigo[ea] = r;
                }
            }
        }
        else if (c == 2) // quer ser inimigo
        {
            if (a == b)
            {
                cout << "-1\n"; // sao amigos, nao pode ser inimigo
            }
            else if (ea != -1 && findd(ea, link) == b)
            {
                // ja sao inimigos, nao faz nada
            }
            else
            {
                if (ea != -1)
                    unite(b, ea, link, sizee); // inimigo do meu inimigo e meu amigo
                if (eb != -1)
                    unite(a, eb, link, sizee);
                a = findd(a, link);
                b = findd(b, link);
                inimigo[a] = b;
                inimigo[b] = a;
            }
        }
        else if (c == 3) // sao amigos?
        {
            cout << (a == b) << "\n";
        }
        else // c == 4, sao inimigos?
        {
            cout << (ea != -1 && findd(ea, link) == b) << "\n";
        }

        cin >> c >> x >> y;
    }
    return 0;
}