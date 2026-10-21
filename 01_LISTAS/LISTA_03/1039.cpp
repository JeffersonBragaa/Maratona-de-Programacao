#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int r1, r2, x1, x2, y1, y2; 
    double dist;
    
    while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2){
        
        dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        
        if(dist + r2 <= r1){
            
            cout << "RICO" << "\n";
        }else{
            cout << "MORTO" << "\n";
        }
    }
    
    return 0;
}