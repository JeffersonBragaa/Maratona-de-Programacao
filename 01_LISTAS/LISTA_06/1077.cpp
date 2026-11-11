
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, int> precedencia = {
        {'(', 1}, {')', 1}, {'^', 2}, {'*', 3}, {'/', 3}, {'+', 4}, {'-', 4}};

    int n;
    cin >> n;

    while (n--)
    {
        string ex;
        stack<char> p;

        cin >> ex;

        for (int i = 0; i < ex.size(); i++)
        {
            char x = ex[i];

            if (!precedencia.count(x))
            {
                cout << x;
            }
            else if (x == '(')
            {
                p.push(x);
            }
            else if (x == ')')
            {
                while (!p.empty() && p.top() != '(')
                {
                    cout << p.top();
                    p.pop();
                }

                if (!p.empty())
                    p.pop();
            }
            else
            {
                while (!p.empty() && p.top() != '(' &&
                       (precedencia[p.top()] < precedencia[x] ||
                        (precedencia[p.top()] == precedencia[x] && x != '^')))
                {

                    cout << p.top();
                    p.pop();
                }

                p.push(x);
            }
        }

        while (!p.empty())
        {
            cout << p.top();
            p.pop();
        }

        cout << '\n';
    }

    return 0;
}
