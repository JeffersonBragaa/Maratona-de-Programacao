#include <bits/stdc++.h>
using namespace std;

int main() {
    int b, z, n, m;

    while (cin >> b >> z && b && z) {
        cin >> n >> m;

        vector<int> beto(b), zeca(z);

        for (int &x : beto)
            cin >> x;
        for (int &x : zeca)
            cin >> x;

        sort(beto.begin(), beto.end());
        sort(zeca.begin(), zeca.end());

        if (beto[n - 1] < zeca[z - m])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
