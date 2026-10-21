#include <bits/stdc++.h>

using namespace std;

int main (){

    string s;
    set<string> joias;

    while(cin >> s){
        joias.insert(s);
    }

    cout << joias.size() << "\n";

    return 0;
}