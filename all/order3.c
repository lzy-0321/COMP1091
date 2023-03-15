//25/5/2021
//z5340468
//Ordering Three Integers

#include <stdio.h>
int main(void) {
    
    int x, y, z;
    
    printf("Enter integer: ");
    scanf("%d", &x);
    printf("Enter integer: ");
    scanf("%d", &y);
    printf("Enter integer: ");
    scanf("%d", &z);
    printf("The integers in order are: ");
    
    if (x < y && y < z) {
        printf("%d %d %d\n", x, y, z);
    }
    if (x < z && z < y) {
        printf("%d %d %d\n", x, z, y);
    }
    if (y < x && x < z) {
        printf("%d %d %d\n", y, x, z);
    }
    if (y < z && z < x) {
        printf("%d %d %d\n", y, z, x);
    }
    if (z < x && x < y) {
        printf("%d %d %d\n", z, x, y);
    }
    if (z < y && y < x) {
        printf("%d %d %d\n", z, y, x);
    }
    if (x == y && z > x) {
        printf("%d %d %d\n", x, y, z);
    }
    if (x == y && z < x) {
        printf("%d %d %d\n", z, x, y);
    }
    if (z == y && z > x) {
        printf("%d %d %d\n", x, y, z);
    }
    if (x == z && y > x) {
        printf("%d %d %d\n", x, z, y);
    }
    if (x == z && y < x) {
        printf("%d %d %d\n", y, x, z);
    }
    if (z == y && z < x) {
        printf("%d %d %d\n", y, z, x);
    }
    if (x == y && x == z) {
        printf("%d %d %d\n", x, y, z);
    }
    return 0;
} 
