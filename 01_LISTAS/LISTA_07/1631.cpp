
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int x[100], y[100];

    while (cin >> n && n != 0) {
        double somaX = 0, somaY = 0;

        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];

            somaX += x[i];
            somaY += y[i];
        }

        double menor = DBL_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dx = x[j] - x[i];
                double dy = y[j] - y[i];

                double distancia = sqrt(dx * dx + dy * dy);

                if (distancia == 0) {
                    continue;
                }

                double diferenca = dx * (somaY - n * y[i])
                                 - dy * (somaX - n * x[i]);

                diferenca = abs(diferenca) / distancia;

                menor = min(menor, diferenca);
            }
        }

        if (menor == DBL_MAX) {
            menor = 0;
        }

        cout << fixed << setprecision(3) << menor << endl;
    }

    return 0;
}
