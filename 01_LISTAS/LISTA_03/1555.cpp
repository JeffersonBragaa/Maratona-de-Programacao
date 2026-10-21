#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; 

    cin >> n;

    while(n--){
    
        int x, y;
        cin >> x >> y;
    
        int r = (3 * x) * (3 * x) + (y * y);
        int b = 2 * (x * x) + (5 * y) * (5 * y);
        int c = -100 * x + (y * y * y);
    
        if (r > b && r > c)
            cout << "Rafael ganhou" << endl;
        else if (b > r && b > c)
            cout << "Beto ganhou" << endl;
        else
            cout << "Carlos ganhou" << endl;
    }
    

    return 0;
}