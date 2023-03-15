//2/5/2021
//z5340468
//Draw an X

#include <stdio.h>
#include <math.h>

int main(void) {
    
    int x, y, n;
   
    y = 0;
    
    printf("Enter size: ");
    scanf("%d", &n);
    
    if (n - 1 % 2 ==0 || n >= 5) {
        while (y < n) {
            x = 0;
            while (x < n) {
                if (x == y) {
                    printf("*");
                }
                else if (x == n - (y + 1 )) {
                    printf("*");
                }
                else {
                    printf("-");
                }
                x = x + 1;
             }
             printf("\n");
             y = y + 1;
        }
    }
    return 0;
} 
