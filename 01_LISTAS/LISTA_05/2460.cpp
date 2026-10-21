#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m, x;
    bool primeiro = true;
    cin >> n;
    vector<int> v;
    unordered_set<int> s;
    while (n--)
    {
        cin >> x;
        v.push_back(x);
        s.insert(x);
    }
    cin >> m;

    while (m--)
    {

        cin >> x;

        s.erase(x);
    }

    for (int i = 0; i < v.size(); i++)
    {

        if (s.count(v[i]))
        {

            if (primeiro)
            {

                cout << v[i];
                primeiro = false;
            }
            else
            {
                cout << " " << v[i];
            }
        }
    }

    cout << "\n";

    return 0;
}