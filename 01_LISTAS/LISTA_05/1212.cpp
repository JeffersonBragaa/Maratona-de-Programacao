#include <bits/stdc++.h>

using namespace std; 

int main () {
    
    string x, y; 
    int xi, yi, i, curry = 0, temp = 0; 

    cin >> x >> y;

    while(!(x == "0" && y == "0")){

        while(x.size() < y.size()){
            x = "0" + x;
        }
        while(y.size() < x.size()){
            y = "0" + y;
        }
         
        for(i = x.size() - 1; i >= 0; i--){
            if(temp + x[i] - '0' + y[i] - '0' >= 10){
                curry++;
                temp = 1;
            }
            else{
                temp = 0;
            }
        }

        if(curry > 1){
            cout << curry << " carry operations.\n";
        }
        else if(curry == 1){
            cout << "1 carry operation.\n";
        }
        else{
            cout << "No carry operation.\n";
        }

        curry = 0;
        temp = 0;

        cin >> x >> y;
    }
    
    return 0;
}