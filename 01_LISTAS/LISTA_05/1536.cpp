#include <bits/stdc++.h>

using namespace std;

int main (){

    int n, a, b, c, d, p1, p2, g1, g2;
    char x;

    cin >> n;

    while(n--){

        cin >> a >> x >> b;
        cin >> c >> x >> d;

        p1 = 0;
        p2 = 0;

        if(a > b) p1 += 3;
        else if(a < b) p2 += 3;
        else { p1++; p2++; }

        if(c > d) p2 += 3;
        else if(c < d) p1 += 3;
        else { p1++; p2++; }

        g1 = a + d;
        g2 = b + c;

        if(p1 > p2){
            cout << "Time 1\n";
        }
        else if(p2 > p1){
            cout << "Time 2\n";
        }
        else if(g1 - g2 > 0){
            cout << "Time 1\n";
        }
        else if(g1 - g2 < 0){
            cout << "Time 2\n";
        }
        else if(d > b){
            cout << "Time 1\n";
        }
        else if(b > d){
            cout << "Time 2\n";
        }
        else{
            cout << "Penaltis\n";
        }
    }

    return 0;
}