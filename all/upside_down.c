//z5340468
//20/5/2021
//Print The Direction of Three Numbers

#include <stdio.h>

int main(void) {

    double x, y, z;
    
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    
    if (x < y && y < z) {
        printf("up\n");
    }    
    else if (x > y && y > z) {
        printf("down\n");
    }
    else {
        printf("neither\n");  
    }
    
    return 0;
}          
