#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int brinde = 0;

    stack<char> painel;

    painel.push('F');
    painel.push('A');
    painel.push('C');
    painel.push('E');

    while (n--) {

        char letras[4];

        for (int i = 0; i < 4; i++) {
            cin >> letras[i];
        }

        stack<char> temp = painel;

        bool ganhou = true;

        for (int i = 0; i < 4; i++) {

            if (temp.top() != letras[i]) {
                ganhou = false;
                break;
            }

            temp.pop();
        }

        if (ganhou) {

            brinde++;

            for (int i = 0; i < 4; i++) {
                painel.pop();
            }

            if (painel.empty()) {
                painel.push('F');
                painel.push('A');
                painel.push('C');
                painel.push('E');
            }

        } else {

            for (int i = 0; i < 4; i++) {
                painel.push(letras[i]);
            }
        }
    }

    cout << brinde << '\n';

    return 0;
}