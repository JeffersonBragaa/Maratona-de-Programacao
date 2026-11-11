#include <bits/stdc++.h>

using namespace std;

// A funcao find() recebe um elemento X e retorna o representativo de X.
int findd(int x, vector<int> &link)
{
    return (x == link[x]) ? x : (link[x] = findd(link[x], link));
}

// A funcao same() verifica se os elementos A e B pertencem ao mesmo conjunto (sao amigos).
int same(int a, int b, vector<int> &link)
{
    return findd(a, link) == findd(b, link);
}

// A funcao unite() mescla os conjuntos que contem os elementos A e B.
// Agora devolve o representativo do conjunto resultante.
void unite(int a, int b, vector<int> &link, vector<int> &sizee)
{
    a = findd(a, link);
    b = findd(b, link);

    if (a == b)
        return;

    if (sizee[a] < sizee[b])
        std::swap(a, b);

    sizee[a] += sizee[b];
    link[b] = a;

}

int main (){
    
    int n, m, i, k, x, ant, rep; 

    cin >> n >> m;

    while(n || m){

        vector<int> link(n); 
        vector<int> sizee(n, 1); 

        for(i = 0; i < n; i++){
            link[i] = i;
        }

        while(m--){
            cin >> k;

            for(i = 0; i < k; i++){
                cin >> x;
                
                if(i == 0){
                    ant = x; 
                    continue;
                } 

                unite(ant, x, link, sizee);
                ant = x; 

            }

            
        }
        
        rep = findd(0, link);
        
        cout << count(link.begin(), link.end(), rep) << endl;

        cin >> n >> m;

        
    }

    return 0;
}