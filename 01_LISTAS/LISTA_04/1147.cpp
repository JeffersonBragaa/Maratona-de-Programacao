#include <bits/stdc++.h>
using namespace std;

int main()
{
    string posCavalo, posPeao;
    int caso = 1;

    // os 8 movimentos possíveis do cavalo (em "L")
    int dl[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dc[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    while (cin >> posCavalo && posCavalo != "0")
    {
        // atacada[linha][coluna] = true se algum peão ataca essa casa
        bool atacada[8][8] = {};

        // posição do cavalo: "4c" -> linha 3, coluna 2 (começando do 0)
        int linhaCavalo = posCavalo[0] - '1';
        int colunaCavalo = posCavalo[1] - 'a';

        // lê os 8 peões e marca as casas que cada um ataca
        for (int i = 0; i < 8; i++)
        {
            cin >> posPeao;

            int linha = posPeao[0] - '1';
            int coluna = posPeao[1] - 'a';

            // peão preto ataca a linha de baixo, nas duas diagonais
            int linhaAtaque = linha - 1;

            if (linhaAtaque >= 0)
            {
                if (coluna - 1 >= 0)
                    atacada[linhaAtaque][coluna - 1] = true;

                if (coluna + 1 < 8)
                    atacada[linhaAtaque][coluna + 1] = true;
            }
        }

        // testa cada movimento do cavalo
        int seguros = 0;

        for (int k = 0; k < 8; k++)
        {
            int novaLinha = linhaCavalo + dl[k];
            int novaColuna = colunaCavalo + dc[k];

            // precisa estar dentro do tabuleiro
            bool dentro = novaLinha >= 0 && novaLinha < 8 && novaColuna >= 0 && novaColuna < 8;

            if (dentro && !atacada[novaLinha][novaColuna])
                seguros++;
        }

        cout << "Caso de Teste #" << caso << ": " << seguros << " movimento(s).\n";
        caso++;
    }

    return 0;
}