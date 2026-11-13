
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, L, H;

    while (cin >> n) {
        cin >> L >> H;

        double menor = L;
        double anteriorX = 0, anteriorY = 0;

        for (int i = 0; i < n; i++) {
            double yi, xf, yf;
            cin >> yi >> xf >> yf;

            double xi;

            if (i % 2 == 0) {
                xi = 0;
                menor = min(menor, L - xf);
            }
            else {
                xi = L;
                menor = min(menor, xf);
            }

            if (i > 0) {
                double dx = xf - xi;
                double dy = yf - yi;

                double t = ((anteriorX - xi) * dx +
                            (anteriorY - yi) * dy) /
                           (dx * dx + dy * dy);

                t = max(0.0, min(1.0, t));

                double x = xi + t * dx;
                double y = yi + t * dy;

                double distancia = sqrt(
                    (anteriorX - x) * (anteriorX - x) +
                    (anteriorY - y) * (anteriorY - y)
                );

                menor = min(menor, distancia);
            }

            anteriorX = xf;
            anteriorY = yf;
        }

        cout << fixed << setprecision(2) << menor << endl;
    }

    return 0;
}
