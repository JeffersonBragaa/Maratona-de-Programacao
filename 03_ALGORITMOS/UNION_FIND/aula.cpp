#include <bits/stdc++.h>
using namespace std;

// Aula 10: Union-Find Disjoint Sets (slides 36 a 38).

// Versao inicial do slide 36:
// A funcao find() recebe um elemento X e retorna o representativo de X.
// int find(int x, int link[])
// {
//     while (x != link[x]) x = link[x];
//     return x;
// }

// Versao com compressao de caminho apresentada no slide 38.
// A funcao find() recebe um elemento X e retorna o representativo de X.
int find(int x, int link[])
{
    return (x == link[x]) ? x : (link[x] = find(link[x], link));
}

// A funcao same() verifica se os elementos A e B pertencem ao mesmo conjunto.
int same(int a, int b, int link[])
{
    return find(a, link) == find(b, link);
}

// A funcao unite() mescla os conjuntos que contem os elementos A e B
void unite(int a, int b, int link[], int size[])
{
    a = find(a, link);
    b = find(b, link);

    if (a == b) return; // A e B ja estao no mesmo conjunto

    if (size[a] < size[b]) std::swap(a, b);

    size[a] += size[b];
    link[b] = a;
}

int main()
{
    // O indice 0 nao e usado no exemplo da aula, que tem elementos de 1 a 8.
    const int N = 9;

    // variaveis
    int link[N];
    int size[N];

    // inicializacao
    for (int i = 0; i < N; i++) link[i] = i; // i
    for (int i = 0; i < N; i++) size[i] = 1; // um!

    // Unioes mostradas nos slides 28 a 34.
    unite(4, 1, link, size);
    unite(7, 4, link, size);
    unite(2, 3, link, size);
    unite(6, 3, link, size);
    unite(8, 3, link, size);

    cout << "1 e 7 conectados? " << (same(1, 7, link) ? "sim" : "nao") << '\n';
    cout << "1 e 8 conectados? " << (same(1, 8, link) ? "sim" : "nao") << '\n';
}
