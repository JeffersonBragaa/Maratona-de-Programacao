#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    if (m <= 2) {
        cout << "nova\n";
    }
    else if (m >= 97) {
        cout << "cheia\n";
    }
    else if (n < m) {
        cout << "crescente\n";
    }
    else {
        cout << "minguante\n";
    }

    return 0;
}