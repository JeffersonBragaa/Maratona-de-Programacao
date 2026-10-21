#include <bits/stdc++.h>
using namespace std;

int valores[500], esquerda[500], direita[500];
vector<int> percurso;

void percorrer(int no, int tipo)
{
    if (no == -1)
        return;

    if (tipo == 0)
        percurso.push_back(valores[no]);

    percorrer(esquerda[no], tipo);

    if (tipo == 1)
        percurso.push_back(valores[no]);

    percorrer(direita[no], tipo);

    if (tipo == 2)
        percurso.push_back(valores[no]);
}

void imprimir(string titulo)
{
    cout << titulo;

    for (int posicao = 0; posicao < (int)percurso.size(); posicao++)
    {
        if (posicao > 0)
            cout << " ";

        cout << percurso[posicao];
    }

    cout << "\n";
    percurso.clear();
}

int main()
{
    int casos;
    cin >> casos;

    for (int caso = 1; caso <= casos; caso++)
    {
        int quantidade;
        cin >> quantidade;

        for (int no = 0; no < quantidade; no++)
        {
            cin >> valores[no];

            esquerda[no] = -1;
            direita[no] = -1;

            if (no == 0)
                continue;

            int atual = 0;

            while (true)
            {
                if (valores[no] < valores[atual])
                {
                    if (esquerda[atual] == -1)
                    {
                        esquerda[atual] = no;
                        break;
                    }

                    atual = esquerda[atual];
                }
                else
                {
                    if (direita[atual] == -1)
                    {
                        direita[atual] = no;
                        break;
                    }

                    atual = direita[atual];
                }
            }
        }

        cout << "Case " << caso << ":\n";

        percorrer(0, 0);
        imprimir("Pre.: ");

        percorrer(0, 1);
        imprimir("In..: ");

        percorrer(0, 2);
        imprimir("Post: ");

        cout << "\n";
    }

    return 0;
}
