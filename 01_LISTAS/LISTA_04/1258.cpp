#include <bits/stdc++.h>
using namespace std;

struct Aluno
{
    string nome;
    string cor;
    char tam;
};

bool comparar(const Aluno &a, const Aluno &b)
{
    if (a.cor != b.cor)
        return a.cor < b.cor;

    if (a.tam != b.tam)
        return a.tam > b.tam;

    return a.nome < b.nome;
}

int main()
{
    int n;
    bool primeiro = true;

    while (cin >> n && n != 0)
    {
        vector<Aluno> alunos(n);

        for (int i = 0; i < n; i++)
        {
            cin >> ws;
            getline(cin, alunos[i].nome);
            cin >> alunos[i].cor >> alunos[i].tam;
        }

        sort(alunos.begin(), alunos.end(), comparar);

        if (!primeiro)
            cout << "\n";
        primeiro = false;

        for (int i = 0; i < n; i++)
            cout << alunos[i].cor << " " << alunos[i].tam << " " << alunos[i].nome << "\n";
    }

    return 0;
}