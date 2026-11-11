
#include <bits/stdc++.h>

using namespace std;

int main() {

    long double c = 300000000.0;
    int v;
    cin >> v;

    long double lambda = 700.0 * sqrt((c - v) / (c + v));

    if(lambda < 400) {
        cout << "invisivel\n";
    }
    else if(lambda < 425) {
        cout << "violeta\n";
    }
    else if(lambda < 445) {
        cout << "anil\n";
    }
    else if(lambda < 500) {
        cout << "azul\n";
    }
    else if(lambda < 575) {
        cout << "verde\n";
    }
    else if(lambda < 585) {
        cout << "amarelo\n";
    }
    else if(lambda < 620) {
        cout << "laranja\n";
    }
    else if(lambda < 750) {
        cout << "vermelho\n";
    }
    else {
        cout << "invisivel\n";
    }

    return 0;
}
