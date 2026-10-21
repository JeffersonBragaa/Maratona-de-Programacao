#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;


    int peso[14] = {0};
    peso[4]  = 1;
    peso[5]  = 2;
    peso[6]  = 3;
    peso[7]  = 4;
    peso[12] = 5;  
    peso[11] = 6; 
    peso[13] = 7;  
    peso[1]  = 8;  
    peso[2]  = 9;
    peso[3]  = 10;

    long long aVence = 0, bVence = 0;

    while (n--) {
        int a[3], b[3];
        cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];

        int contA = 0, contB = 0;
        for (int i = 0; i < 3; i++) {
            if (peso[a[i]] >= peso[b[i]]) contA++;
            else contB++;
        }

        if (contA > contB) aVence++;
        else if (contB > contA) bVence++;
    }

    cout << aVence << " " << bVence << "\n";
    return 0;
}