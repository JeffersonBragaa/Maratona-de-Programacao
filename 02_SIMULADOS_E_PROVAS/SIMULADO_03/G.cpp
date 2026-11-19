#include <bits/stdc++.h> 


using namespace std; 

int findd(int x, vector<int> &link){
	return (x == link[x]) ? x : (link[x] = findd(link[x], link));
}

int same(int a, int b, vector<int> &link){

	return findd(a, link) == findd(b, link); 
}

void unite(int a, int b,vector<int> &link,  vector<int> &sizee){
	a = findd(a, link);
	b = findd(b, link);
	
	if(a == b) return; 
	
	if(sizee[a] < sizee[b]){
		swap(a, b);
	}
	
	sizee[a] += sizee[b];
	link[b] = a;
}

int main (){

	int n, k, a, b;
	char c;  
	
	cin >> n >> k; 
	
	while(n || k){
		
		vector<int> link(n+1); 
		vector<int> sizee(n+1, 1); 
		
		for(int i = 1; i <= n; i++) link[i] = i; 
		
		while(k--){
			cin >> c >> a >> b; 
			
			if(c == 'C'){
				
				if(same(a, b, link)){
					cout << "S" << endl; 	
				}else{
					cout << "N" << endl;
				}
			}else{
				unite(a, b, link, sizee); 
			}
		}
		
		cin >> n >> k;
	}
	
	return 0;
}
