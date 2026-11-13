
#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, N, L;
    double b, B, H;
    const double pi = acos(-1.0);

    cin >> C;

    while (C--) {
        cin >> N >> L;
        cin >> b >> B >> H;

        double volume = (double)L / N;
        double inicio = 0, fim = H;
        double h, r, v;

        for (int i = 0; i < 100; i++) {
            h = (inicio + fim) / 2.0;

            r = b + (B - b) * h / H;

            v = pi * h * (b * b + b * r + r * r) / 3.0;

            if (v < volume) {
                inicio = h;
            }
            else {
                fim = h;
            }
        }

        cout << fixed << setprecision(2);
        cout << (inicio + fim) / 2.0 << endl;
    }

    return 0;
}
