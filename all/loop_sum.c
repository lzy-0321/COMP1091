//2/5/2021
//z5340468
//Calculate the Sum of Some Numbers

#include <stdio.h>

int main(void) {
   
    int x, y, n, sum;
    
    x = 1;
    sum = 0;

    printf("How many numbers: ");
    scanf("%d", &n);
        if ( n >= 0 ) {
            while (x < n + 1) {
                scanf("%d", &y);
                sum = sum + y;
                x = x + 1;
            }
        }    
        printf("The sum is: %d\n", sum);
    return 0;
}       
