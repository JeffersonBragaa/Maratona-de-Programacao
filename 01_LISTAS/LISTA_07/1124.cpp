
#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, C, R1, R2;

    while (cin >> L >> C >> R1 >> R2) {
        if (L == 0 && C == 0 && R1 == 0 && R2 == 0)
            break;

        if (2 * R1 > L || 2 * R1 > C ||
            2 * R2 > L || 2 * R2 > C) {
            cout << "N" << endl;
        }
        else {
            int dx = L - R1 - R2;
            int dy = C - R1 - R2;

            int distancia = dx * dx + dy * dy;
            int soma = (R1 + R2) * (R1 + R2);

            if (distancia >= soma) {
                cout << "S" << endl;
            }
            else {
                cout << "N" << endl;
            }
        }
    }

    return 0;
}
