#include <bits/stdc++.h>

using namespace std;


int main (){

    int b, n, i, d, c, v;
    bool verifica = true;
    cin >> b >> n;


    while( b || n){

        vector<int> b_reservas(b+1);

        for(i = 1; i <= b; i++){
            cin >> b_reservas[i];
        }

        while(n--){
            cin >> d >> c >> v;

            b_reservas[d] -= v;
            b_reservas[c] += v;
        }

        for(i = 1; i <= b; i++){

            if(b_reservas[i] < 0){

                cout << 'N' << endl;
                verifica = false;
                break;
            }
        }

        if(verifica){
            cout << 'S' << endl;
        }

        cin >> b >> n;
        verifica = true;

    }


    return 0;
}
