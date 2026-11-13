
#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;

    while (cin >> a >> b >> c) {

        if (a + b <= c || a + c <= b || b + c <= a) {
            cout << fixed << setprecision(3) << -1.0 << endl;
        }
        else {
            double s = (a + b + c) / 2.0;

            double area = sqrt(s * (s - a) * (s - b) * (s - c));

            area = area * 4.0 / 3.0;

            cout << fixed << setprecision(3) << area << endl;
        }
    }

    return 0;
}
