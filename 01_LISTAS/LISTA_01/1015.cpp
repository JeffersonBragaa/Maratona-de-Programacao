#include <bits/stdc++.h>
int main() {
 
    double x1, x2, y1, y2, dist = 0; 
    
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    
    dist = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))); 
    
    printf("%.4f\n", dist); 
    
    return 0;
}