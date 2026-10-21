#include <bits/stdc++.h>

using namespace std;

int main (){

    int n, c, melhor, carac;
    string atual;

    while(cin >> n){

        vector<string> pilha;
        carac = 0;

        while(n--){

            cin >> atual;
            melhor = 0;

            for(string &w : pilha){
                c = 0;
                while(c < w.size() && c < atual.size() && w[c] == atual[c]){
                    c++;
                }
                melhor = max(melhor, c);
                if(melhor == atual.size()){
                    break;
                }
            }

            carac += melhor;

            if(melhor < atual.size()){
                pilha.push_back(atual);
            }
        }
        cout << carac << "\n";
    }
    return 0;
}