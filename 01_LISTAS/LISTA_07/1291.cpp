
#include <bits/stdc++.h>
using namespace std;

int main() {
    double a;
    const double pi = acos(-1.0);

    while (cin >> a) {
        double area = a * a;

        double listrada = (1 + pi / 3 - sqrt(3.0)) * area;
        double pontilhada = (pi / 3 + 2 * sqrt(3.0) - 4) * area;
        double quadriculada = (4 - 2 * pi / 3 - sqrt(3.0)) * area;

        cout << fixed << setprecision(3);
        cout << listrada << " " << pontilhada << " " << quadriculada << endl;
    }

    return 0;
}
