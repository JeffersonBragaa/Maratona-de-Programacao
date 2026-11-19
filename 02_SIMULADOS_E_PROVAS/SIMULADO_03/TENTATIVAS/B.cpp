#include <bits/stdc++.h> 

using namespace std; 

int main (){

	
	long long int n, soma = 2; 
	
	cin >> n; 
	
	for(int i = 1; i <= n; i++){
		soma *= soma;
	}
	
	for(int i = 1; i <= n; i++){
		soma = soma / 2;
	}
	
	cout << soma*soma << endl;
	
}
