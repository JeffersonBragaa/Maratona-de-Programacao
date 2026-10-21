#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, i, j, maior = 0;
    string palavra;
    bool primeiro = true;

    cin >> n;
    while (n--)
    {
        vector<string> v[51];
        primeiro = true;
        while (cin >> palavra)
        {
            v[palavra.size()].push_back(palavra);

            if(palavra.size() > maior) maior = palavra.size();
            if (cin.peek() == '\n')
                break;
        }

        for (i = maior; i >= 1; i--)
        {

            if (v[i].empty())
            {
                continue;
            }
            else
            {
                for (j = 0; j < v[i].size(); j++)
                {
                    if(primeiro){
                        cout << v[i][j] ;
                        primeiro = false;
                        continue;
                    }

                    cout << " " << v[i][j] ;

                }
            }
        }
        maior = 0;
        cout << "\n";
    }

    return 0;
}