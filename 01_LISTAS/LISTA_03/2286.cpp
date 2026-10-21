#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, n1, n2, i = 1, j; 
    string A, B; 

    cin >> n; 

    while(n != 0)
    {
        cin >> A >> B; 
        cout << "Teste " << i << "\n";
        for(j = 0; j < n; j++){
            
            cin >> n1 >> n2;
            if((n1 + n2) % 2 == 0){
                cout << A << "\n";
            }
            else{
                cout << B << "\n";
            }
        }
        cout << "\n";
        i++;
        cin >> n;
    }
    

    return 0;
}