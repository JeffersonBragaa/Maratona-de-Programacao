#include <bits/stdc++.h> 

using namespace std; 

constexpr int T = 100;
constexpr int N = 20;
constexpr int V = 100000; 


int solve(int x, vector<int> &f, vector<int> &values){

	values[0] = 0; 
	
	for(int i = 1; i <= x; i++){
	
		values[i] = V; 
		
		for(auto c: f){
			if(i - c >= 0){
				values[i] = min(values[i], values[i - c] + 1); 
			}
		}
	} 
	
	return values[x]; 
}
int main () {

	
	int t, n, v, r; 
	
	cin >> t; 
	
	while(t--){
	
		cin >> n >> v; 
		
		vector<int> values(v+1, 0);
		vector<int> f(n); 
		for(int i = 0; i < n; i++){
			cin >> f[i]; 
		}
		
		
		r = solve(v, f, values);
		
		if(r == V){
			cout << "-1" << endl; 
		}else{
			cout << r << endl; 
		}
	}
	
	return 0;
}
