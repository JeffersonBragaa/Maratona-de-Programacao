#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, i;
    string frase;

    cin >> n;
    cin.ignore();

    while(n--) {

        getline(cin, frase);

        vector<char> final;

        for(i = 0; i < frase.size(); i++) {

            if(frase[i] != ' ' && (i == 0 || frase[i - 1] == ' ')) {
                final.push_back(frase[i]);
            }
        }

        for(i = 0; i < final.size(); i++) {
            cout << final[i];
        }

        cout << "\n";
    }

    return 0;
}