#include <bits/stdc++.h>

using namespace std;

int main()
{

    int i;
    string ris;
    char x;

    vector<char> c;
    stack<char> in;

    cin >> ris;

    for (i = 0; i < ris.size(); i++)
    {
        if (ris[i] == 'a' || ris[i] == 'e' || ris[i] == 'i' || ris[i] == 'o' || ris[i] == 'u'){
            c.push_back(ris[i]);
            in.push(ris[i]);
        }
    }
    i = 0;
    bool verifica = true;
    while(!in.empty()){
        x = in.top();
        in.pop();

        if(x != c[i]){
            verifica = false; 
            break;
        }else{
            i++;
        }

    }

    if(verifica) cout << "S\n";
    else cout << "N\n";

    return 0;
}
