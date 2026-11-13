
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    int teste = 1;

    while (cin >> x1 >> y1 >> x2 >> y2) {
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
            break;

        int n;
        cin >> n;

        int quantidade = 0;

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;

            if (x >= x1 && x <= x2 &&
                y >= y2 && y <= y1) {
                quantidade++;
            }
        }

        cout << "Teste " << teste << endl;
        cout << quantidade << endl;

        teste++;
    }

    return 0;
}
