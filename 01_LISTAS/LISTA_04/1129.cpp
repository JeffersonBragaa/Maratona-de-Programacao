#include <bits/stdc++.h>
using namespace std;

int main () {
    
    int n, x, i, cont = 0, letraIndice; 
    vector<char> letra = {'A', 'B', 'C', 'D', 'E'}; 


    cin >> n; 

    while(n != 0){
        while(n--){
            for(i = 0; i < 5; i++){
                cin >> x;
                if(x >= 0 && x <= 127){
                    letraIndice = i;
                    cont++; 
                }
            }
            if(cont == 1){
                cout << letra[letraIndice] << "\n";
                cont = 0;
            }
            else{
                cout << "*\n";
                cont = 0;
            }
        }
        cin >> n;
    }
    
    return 0;
}