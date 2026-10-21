#include <bits/stdc++.h>
using namespace std; 


int main () {

    int n, m, i, x, cont; 

    cin >> n;

    while(n--){
        cin >> m;
        vector<int> v(m);  
        unordered_map<int, int> verifica; 
        cont = 0;
        
        for(i = 0; i < m; i++){
            cin >> x;
            v[i] = x;
            
            verifica[x] = i + 1;
        }

        sort(v.rbegin(), v.rend()); 

        for(i = 0; i < m; i++){
            if(verifica[v[i]] == i + 1 ){
                cont++;
            }
        }

        cout << cont << "\n";

    }



    return 0;
}