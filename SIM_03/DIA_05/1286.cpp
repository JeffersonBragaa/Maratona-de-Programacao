#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    while (cin >> n && n != 0) {
        cin >> p;
        vector<int> t(n + 1), q(n + 1);
        for (int i = 1; i <= n; i++) cin >> t[i] >> q[i];

        vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= p; j++) {
                dp[i][j] = dp[i-1][j];              // não pega
                if (q[i] <= j)                      // pega
                    dp[i][j] = max(dp[i][j], dp[i-1][j - q[i]] + t[i]);
            }
        }

        cout << dp[n][p] << " min.\n";
    }
    return 0;
}