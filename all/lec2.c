
#include <stdio.h> 

int main (void) {
    
    double x;
    int y; 
    int sum;    
    
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);  
    
    sum=x*y;
    
    printf("%lf* %d= %d\n", x, y, sum);
     
    return 0;
}
