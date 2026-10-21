#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, num, i, maior, segundo;
    
    
    cin >> n >> m;
    while(n != 0 && m != 0){
        vector<int> v(10001, 0);
 
        while(n--){
            for(i = 0; i < m; i++){
                cin >> num; 
                v[num]++;
            }
        }
        
        maior = 0;
        segundo = 0;
        for(i = 1; i <= 10000; i++){
            if(v[i] > v[maior]){
                segundo = maior; 
                maior = i;
            }
            else if(v[i] > v[segundo] && i != maior){
                segundo = i;
            }
        }
        
        for(i = 1; i <= 10000; i++){
            if(v[i] == v[segundo]){
                cout << i << " ";
            }
        }
        
        cout << "\n";
        cin >> n >> m;
    }
    
   
 
    return 0;
}