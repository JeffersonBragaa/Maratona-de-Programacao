#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;

    while (N--) {
        long long T;
        cin >> T;

        long long diff = 2015 - T;

        if (diff > 0) {
            cout << diff << " D.C." << endl;
        } else {
            cout << (-diff + 1) << " A.C." << endl;
        }
    }

    return 0;
}