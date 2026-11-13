
#include <bits/stdc++.h>
using namespace std;

inline int lerInteiro() {
    int n = 0;
    int c = getchar_unlocked();

    while (c <= ' ') {
        c = getchar_unlocked();
    }

    while (c >= '0' && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }

    return n;
}

int main() {
    int N = lerInteiro();
    int AAH = lerInteiro();

    int anteriorX = 0, anteriorY = 0, anteriorL = 0;
    bool possivel = true;

    long long alcance = 4LL * AAH * AAH;

    for (int i = 0; i < N; i++) {
        int x = lerInteiro();
        int y = lerInteiro();
        int L = lerInteiro();

        if (i > 0 && possivel) {
            long long dx = max(0, 2 * abs(x - anteriorX) - L - anteriorL);
            long long dy = max(0, 2 * abs(y - anteriorY) - L - anteriorL);

            if (dx * dx + dy * dy > alcance) {
                possivel = false;
            }
        }

        anteriorX = x;
        anteriorY = y;
        anteriorL = L;
    }

    if (possivel) {
        puts("YEAH");
    }
    else {
        puts("OUCH");
    }

    return 0;
}
