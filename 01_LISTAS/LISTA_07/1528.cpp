
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;

    while (cin >> s) {
        long long a = 0, b = 1, temp;

        for (int i = 0; i < (int)s.size(); i++) {

            if (s[i] == '+') {
                a += b;
            }
            else if (s[i] == '-') {
                a -= b;
            }
            else if (s[i] == '*') {
                temp = a;
                a = -b;
                b = temp;
            }
        }

        if (a == 0 || b == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
