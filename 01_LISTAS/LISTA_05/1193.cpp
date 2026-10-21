#include <bits/stdc++.h>

using namespace std;

string para_hex(long long v, unordered_map<int, char> &hexx){
    string r = "";
    if(v == 0) return "0";
    while(v > 0){
        r = hexx[v % 16] + r;
        v /= 16;
    }
    return r;
}

string para_bin(long long v){
    string r = "";
    if(v == 0) return "0";
    while(v > 0){
        r = char('0' + v % 2) + r;
        v /= 2;
    }
    return r;
}

long long para_dec(string x, string s){
    long long soma = 0;
    int base = 10, i, d;
    if(s == "bin") base = 2;
    else if(s == "hex") base = 16;

    for(i = 0; i < x.size(); i++){
        if(isdigit(x[i])) d = x[i] - '0';
        else d = tolower(x[i]) - 'a' + 10;
        soma = soma * base + d;
    }
    return soma;
}

int main () {

    int n, l = 1; 
    string s, x;
    cin >> n; 

    unordered_map<int, char> hexx = {
        {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'},
        {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'},
        {10, 'a'}, {11, 'b'}, {12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'}
    };

    while(n--){
        cin >> x >> s; 
        cout << "Case " << l << ":\n";
        long long v = para_dec(x, s);
        if(s == "bin"){
            cout << v << " dec\n";
            cout << para_hex(v, hexx) << " hex\n";
        } else if(s == "dec"){
            cout << para_hex(v, hexx) << " hex\n";
            cout << para_bin(v) << " bin\n";
        } else {
            cout << v << " dec\n";
            cout << para_bin(v) << " bin\n";
        }
        cout << "\n";
        l++;
    }
    
    return 0;
}