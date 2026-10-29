#include <bits/stdc++.h> 

using namespace std; 

int main (){

    int n, cont = 0; 

    cin >> n; 
    
    unordered_map<string, bool> mapp; 
    while(n--){
        string poke; 

        cin >> poke; 

        if(mapp[poke]){
            continue;
        }else{
            mapp[poke] = true;
            cont++;
        }
    }

    cout << "Falta(m) " << 151 - cont << " pomekon(s).\n";
    
    return 0;
}