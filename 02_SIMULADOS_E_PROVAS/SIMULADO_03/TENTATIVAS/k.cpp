#include <bits/stdc++.h> 

using namespace std; 

int main () {
	
	string expre; 
	int i;
	char x; 
	
	string a = "()[]<>"; 
	
	
	while(cin >> expre){
		
		stack<char> p;
		
		for(i = 0; i < expre.size(); i++){
			x = expre[i]; 
			
			if(count(a.begin(), a.end(), x) > 0){
				cout << x << endl;
			}
		}
		
		
	}
	
	
	return 0;
}
