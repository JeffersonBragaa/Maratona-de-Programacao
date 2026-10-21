#include <bits/stdc++.h>

int main(){

    double h, a, v;  
    int p1, p2, n, i;
    double delta, t1, t2, tempo, distancia;
    double g = 9.80665;
    double A, B, C;

    while(scanf("%lf", &h) != EOF){

        scanf("%d %d", &p1, &p2); 
        scanf("%d", &n); 

        for(i = 0; i < n; i++){

            scanf("%lf %lf", &a, &v);

            a = a * 3.14159 / 180.0;

            A = -g / 2;
            B = v * sin(a);
            C = h;

            delta = B * B - 4 * A * C;

            t1 = (-B + sqrt(delta)) / (2 * A);
            t2 = (-B - sqrt(delta)) / (2 * A);

            if(t1 > 0){
                tempo = t1;
            }else{
                tempo = t2;
            }

            distancia = (v * cos(a)) * tempo;

            if(distancia >= p1 && distancia <= p2){
                printf("%.5lf -> DUCK\n", distancia);
            }else{
                printf("%.5lf -> NUCK\n", distancia);
            }
        }
    }

    return 0;
}