#include <bits/stdc++.h>
 
int main() {
 
    int vel, temp; 
    double litros; 
    
    scanf("%d", &temp);
    scanf("%d", &vel);
    
    litros = ((double)vel * (double)temp) / 12;
    
    printf("%.3f\n", litros);
 
    return 0;
}