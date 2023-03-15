//z5340468
//18/5/2021
//Area of a Triange

#include <stdio.h>
#include <math.h>
int main (void) {
    
    double x, y, z, s, p, g;
    
    printf("Enter side 1: ");
    scanf("%lf", &x);
    printf("Enter side 2: ");
    scanf("%lf", &y);
    printf("Enter side 3: ");
    scanf("%lf", &z);

    s =  x + y + z;

    p = s / 2;

    g = sqrt(p * (p - x)*(p - y)*(p - z));
    
    if (z < p) {
        printf("Area = %lf \n", g);
    }
    else if (z >= p) {
        printf("Error: triangle inequality violated. \n");
    }
    return 0;
}   
