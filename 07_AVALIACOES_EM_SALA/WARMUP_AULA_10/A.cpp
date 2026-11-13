#include <bits/stdc++.h>

using namespace std;

// A funcao find() recebe um elemento X e retorna o representativo de X.
int findd(int x, vector<int> &link)
{
    while (x != link[x])
        x = link[x];
    return x;
}

// A funcao same() verifica se os elementos A e B pertencem ao mesmo conjunto (sao amigos).
int same(int a, int b, vector<int> &link)
{
    return findd(a, link) == findd(b, link);
}

// A funcao unite() mescla os conjuntos que contem os elementos A e B.
// Agora devolve o representativo do conjunto resultante.
int unite(int a, int b, vector<int> &link, vector<int> &sizee)
{
    a = findd(a, link);
    b = findd(b, link);

    if (a == b)
        return a; // A e B ja estao no mesmo conjunto

    if (sizee[a] < sizee[b])
        std::swap(a, b);

    sizee[a] += sizee[b];
    link[b] = a;
    return a;
}

// NOVO: inimigo[r] guarda UM elemento do conjunto inimigo do conjunto de representante r (ou -1).
// Dois elementos sao inimigos se o conjunto de A e o inimigo do conjunto de B.
int saoInimigos(int a, int b, vector<int> &link, vector<int> &inimigo)
{
    int ra = findd(a, link);
    int rb = findd(b, link);
    return inimigo[ra] != -1 && findd(inimigo[ra], link) == rb;
}

int main()
{
    int n, c, x, y;

    cin >> n;

    vector<int> link(n + 1);
    vector<int> inimigo(n + 1, -1); // substitui o vetor "ini" que nao era usado
    vector<int> sizee(n + 1, 1);    // (no seu codigo estava escrito "sisee" na main)

    for (int i = 0; i <= n; i++)
    {
        link[i] = i;
    }

    cin >> c >> x >> y;
    while (c || x || y)
    {

        if (c == 1) // setFriends
        {
            if (same(x, y, link))
            {
                // ja sao amigos: nada a fazer
            }
            else if (saoInimigos(x, y, link, inimigo))
            {
                cout << "-1\n"; // contradiz o que ja sabia
            }
            else
            {
                int ra = findd(x, link);
                int rb = findd(y, link);
                int ea = inimigo[ra]; // inimigo do conjunto de x (se existir)
                int eb = inimigo[rb]; // inimigo do conjunto de y (se existir)

                int r = unite(ra, rb, link, sizee);

                if (ea != -1 && eb != -1)
                {
                    // os inimigos de amigos tambem viram amigos entre si
                    int re = unite(ea, eb, link, sizee);
                    inimigo[r] = re;
                    inimigo[re] = r;
                }
                else if (ea != -1 || eb != -1)
                {
                    int re = findd(ea != -1 ? ea : eb, link);
                    inimigo[r] = re;
                    inimigo[re] = r;
                }
            }
        }
        else if (c == 2) // setEnemies
        {
            if (same(x, y, link))
            {
                cout << "-1\n"; // sao amigos, nao podem ser inimigos
            }
            else if (saoInimigos(x, y, link, inimigo))
            {
                // ja eram inimigos: nada a fazer, nao imprime nada
            }
            else
            {
                int ra = findd(x, link);
                int rb = findd(y, link);
                int ea = inimigo[ra];
                int eb = inimigo[rb];

                // inimigo do meu inimigo e meu amigo
                if (ea != -1)
                    rb = unite(rb, ea, link, sizee);
                if (eb != -1)
                    ra = unite(ra, eb, link, sizee);

                ra = findd(ra, link);
                rb = findd(rb, link);
                inimigo[ra] = rb;
                inimigo[rb] = ra;
            }
        }
        else if (c == 3) // areFriends
        {
            if (same(x, y, link))
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else // c == 4, areEnemies
        {
            if (saoInimigos(x, y, link, inimigo))
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }

        cin >> c >> x >> y;
    }
    return 0;
}