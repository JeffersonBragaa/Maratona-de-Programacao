#include <bits/stdc++.h>
using namespace std; 

int main (){

    int n; 
    long long x, i;
    bool primo;
    cin >> n; 

    while(n--){
        cin >> x; 
        primo = (x >=2);
        
        for(i = 2; i <= sqrt(x); i++){
            if(x%i == 0){
                primo = false; 
                break;
            }
        }

        if(primo){
            cout << "Prime\n";
        }else{
            cout << "Not Prime\n";
        }

    }
    
    return 0;
}