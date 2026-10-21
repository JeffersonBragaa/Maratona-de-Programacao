#include <bits/stdc++.h>

using namespace std; 

int main () {
    
    int n, b, x, i, j, atual, proximo, soma, mod; 


    cin >> n >> b; 

    while(n || b){
        vector<int> v(n+1, 0); 
        vector<int> bolas;
        v[0] = 1;
        while(b--){
            cin >> x;
            bolas.push_back(x);
        }

        for(i = 0; i < bolas.size(); i++){
            atual = bolas[i];
            for(j = i + 1; j < bolas.size(); j++){
                proximo = bolas[j];

                soma = atual - proximo;
                mod = abs(soma); 

                if(v[mod] == 0){
                    v[mod] = 1;
                }
            }
        }

        if(count(v.begin(), v.end(), 0) > 0){
            cout << "N\n";
        }else{
            cout << "Y\n";
        }

        cin >> n >> b;

    }
    
    return 0;
}