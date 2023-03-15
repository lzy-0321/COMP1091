//24/9/2021
//z5340468
//Print the Absolute Multiple of Two Integers

#include <stdio.h>

int main(void) {
    
    int x, y, n;
    scanf("%d %d", &x, &y);
    if (x < 0) {
        x = -x;
    }
    if (y < 0) {
        y = -y;
    }
    if (x == 0 || y == 0) {
    printf("zero\n");
    }
    else {
        n = x * y;
        printf("%d\n", n);
    }
    
    return 0;
}           
