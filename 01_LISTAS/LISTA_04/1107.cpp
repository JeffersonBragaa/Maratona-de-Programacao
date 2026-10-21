#include <bits/stdc++.h> 

using namespace std;

int main(){
    int a, c, x, i, cont = 0, anterior; 


    cin >> a >> c;

    while(a != 0 && c != 0){
        for(i = 0; i < c; i++){
           cin >> x; 

           if(a - x < c){
            cont++;
           }
        }
        cout << cont << "\n";
        cont = 0; 
        cin >> a >> c;

    }
    return 0;
}