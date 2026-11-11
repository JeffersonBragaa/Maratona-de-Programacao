#include <bits/stdc++.h>
using namespace std;

long long dobroArea() {
    long long x[4], y[4], soma = 0;
    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        soma += x[i] * y[j] - y[i] * x[j];
    }
    return llabs(soma);
}

int main() {
    long long a = dobroArea();
    long long b = dobroArea();
    cout << (a > b ? "terreno A" : "terreno B") << '\n';

    return 0;
}
