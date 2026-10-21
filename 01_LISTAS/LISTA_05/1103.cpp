
#include <bits/stdc++.h>
using namespace std;

int main() {
    int h1, m1, h2, m2;

    while (cin >> h1 >> m1 >> h2 >> m2) {
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
            break;

        int atual = h1 * 60 + m1;
        int alarme = h2 * 60 + m2;

        int result = alarme - atual;

        if (result <= 0)
            result += 1440;

        cout << result << "\n";
    }

    return 0;
}
