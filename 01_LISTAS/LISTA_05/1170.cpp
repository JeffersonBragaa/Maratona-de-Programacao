#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    double c, temp, dia = 0;

    cin >> n;

    while (n--)
    {
        cin >> c;

        while (c > 1)
        {

            temp = c / 2;
            c -= temp;
            dia++;
        }

        cout << dia << " dias\n";
        dia = 0;
    }

    return 0;
}