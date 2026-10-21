#include <bits/stdc++.h> 

using namespace std; 


int main (){
    
    string n1, n2, n3; 

    cin >> n1; 

    if(n1 == "vertebrado"){
        cin >> n2; 
        if(n2 == "ave"){
            cin >> n3;
            if(n3 == "carnivoro"){
                cout << "aguia\n";
            }else{
                cout << "pomba\n";
            }
        }else{
            cin >> n3; 
            if(n3 == "onivoro"){
                cout << "homem\n";
            }else{
                cout << "vaca\n";
            }
        }
    }else{
        cin >> n2;
        if(n2 == "inseto"){
            cin >> n3; 
            if(n3 == "hematofago"){
                cout << "pulga\n";
            }else{ 
                cout << "lagarta\n";
            }
        }else{
            cin >> n3; 
            if(n3 == "hematofago"){
                cout << "sanguessuga\n";
            }else{
                cout << "minhoca\n";
            }
        }

    }
    
    return 0;
}
