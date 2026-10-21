#include <bits/stdc++.h>
using namespace std; 

int main() {
 
    string n; 

    while(cin >> n){
        
        int controla = 0;
        stack<char> ex;
        
        for(int i : n){
            if(i == '('){
                ex.push(i);
            }

            if(i == ')'){
                if(ex.size() > 0){
                    ex.pop();
                }else{
                    controla = 1;
                }
            }
        }
        
        if(ex.size() == 0 && controla == 0){
            cout << "correct\n";
        }else{
            cout << "incorrect\n";
        }
    }
    
    return 0;
}