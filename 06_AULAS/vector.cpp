#include <bits/stdc++.h> 
#include <vector>
#include <iterator>

int main() {

    vector<int> vec; 
    vector<iterator> it;
    //insert 

    vec.push_back(10); 
    vec.push_back(20); 
    vec.push_back(-1); 

    for(int i = 0: i < vec.size(); i++){
        cout << vec[i];
    }


    cout << "\n";

    vec[0] = 2; 


    for(it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";

    cout << "\n";


    return 0;
}