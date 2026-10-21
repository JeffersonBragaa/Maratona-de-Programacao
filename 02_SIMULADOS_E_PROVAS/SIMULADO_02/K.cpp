#include <bits/stdc++.h>
using namespace std;

int main() {
	int b, z;

	while (cin >> b >> z && b && z) {
		set<int> distincts_b;

		int repeated = 0;
		int n, m, x;
		cin >> n >> m;

		int max_b = -1000000001, min_z = 1000000001;

		for (int i = 0; i < b; i++) {
			cin >> x;
			distincts_b.insert(x);
			if (x > max_b)
				max_b = x;
		}

		for (int i = 0; i < z; i++) {
			cin >> x;
			if (distincts_b.find(x) != distincts_b.end())
				repeated++;
			if (x < min_z)
				min_z = x;
		}

		if (min_z < max_b) {
			cout << "NO" << endl;
			continue;
		}

		if (b - repeated < n || z - repeated < m) {
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;
	}

	return 0;
}
