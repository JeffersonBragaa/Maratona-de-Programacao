#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    cin.ignore();

    while(n--) {

        unordered_map<string, bool> v;
        vector<string> prods;

        string p, pr;

        getline(cin, p);

        stringstream ss(p);

        while(ss >> pr) {

            auto it = v.find(pr);

            if(it == v.end()) {
                v[pr] = true;
                prods.push_back(pr);
            }
        }

        sort(prods.begin(), prods.end());

        for(int i = 0; i < prods.size(); i++) {

            if(i > 0)
                cout << " ";

            cout << prods[i];
        }

        cout << "\n";
    }

    return 0;
}