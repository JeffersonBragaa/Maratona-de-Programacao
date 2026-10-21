#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	vector<int> cache(1000000);

	cache[1] = 1;
	for (int i = 2; i < 1000001; i++) {
		long long n = i;
		int sum = 0;
		while (n >= i) {
			if (n % 2 == 0)
				n = n / 2;
			else
				n = (n * 3) + 1;
			sum++;
		}
		cache[i] = sum + cache[n];
	}


	cin >> t;
	while (t--) {
		int i, j;
		cin >> i >> j;

		int begin, end;
		if (i <= j) {
			begin= i;
			end = j;
		} else {
			begin = j;
			end = i;
		}

		int m = -1;
		for (int k = begin; k <= end; k++) {
			int l = cache[k];
			if (l > m) m = l;
		}

	        cout << i << " " << j << " " << m << endl;
	}

	return 0;
}
