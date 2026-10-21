#include <bits/stdc++.h>
using namespace std; 

int main(){
    
    int n, i, j, x, dias; 

    cin >> n; 

    vector<int> v; 
    for(i = 0; i<n; i++){
        cin >> x;   
        v.push_back(x);  
    }
    sort(v.rbegin(), v.rend());
    dias = v[0] + 1;
    for(i = 1; i < v.size(); i++){
        if(v[i] + i + 1> dias){
            dias = v[i] + i +1;
        }
    }

    cout << dias + 1 << "\n";
    

    
    return 0;
}