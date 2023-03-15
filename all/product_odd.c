//10/6/2021
//z5340468
//Calculate product of odd numbers

#include <stdio.h>

int main(void) {
    int x, y, odd = 1;
    
    printf("Enter lower: ");
    scanf("%d", &x);
    printf("Enter upper: ");
    scanf("%d", &y);
    
    if ( x % 2 == 0) {
        x = x + 1;
        while (x < y) {
            odd = odd * x;
            x = x + 2;
        }
    }
    if (x % 2 == 1) {
        if (y - x > 2) {
            x = x + 2;
            while (x < y) {
            odd = odd * x;
            x = x + 2;
        }
        if ((y - x) == 2){
            odd = 1;
        }
    }
    
   
    }
    printf("%d\n", odd);
    return 0;
}
