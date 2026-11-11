#include <bits/stdc++.h>

using namespace std; 

int main (){

    int r; 
    long long int l; 
    long long int v; 
    int baloes; 
    float pi = 3.1415; 
    cin >> r >> l; 

    v = ((double)4/3) * pi * (r * r * r);

    baloes = l / v; 
    cout << baloes << endl;

    
    
    return 0;
}