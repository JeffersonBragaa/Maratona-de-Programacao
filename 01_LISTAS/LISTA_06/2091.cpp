#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    long long int i, a;
    cin >> n;

    while (n != 0)
    {
        unordered_map<long long int, bool> v;

        for (i = 0; i < n; i++)
        {
            cin >> a;

            if (v[a] == true)
            {
                v[a] = false;
            }
            else
            {
                v[a] = true;
            }
        }

        for (const auto &[key, value] : v)
        {
            if (value == true)
            {
                cout << key << endl;
                break;
            }
        }
        cin >> n;
    }

    return 0;
}