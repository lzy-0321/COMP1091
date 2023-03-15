//2/5/2021
//z5340468
//Print the Middle of Three Integers

#include <stdio.h>

int main(void) {
   
    int x, y, z;
   
    printf("Enter integer: ");
    scanf("%d", &x);
    printf("Enter integer: ");
    scanf("%d", &y);
    printf("Enter integer: ");
    scanf("%d", &z);
   
    if (x < y && y < z) {
        printf("Middle: %d\n", y);
    }
    if (x < z && z < y) {
        printf("Middle: %d\n", z);
    }
    if (y < x && x < z) {
        printf("Middle: %d\n", x);
    }
    if (y < z && z < x) {
        printf("Middle: %d\n", z);
    }
    if (z < x && x < y) {
        printf("Middle: %d\n", x);
    }
    if (z < y && y < x) {
        printf("Middle: %d\n", y);
    }
    if (x == y && z > x) {
        printf("Middle: %d\n", x);
    }
    if (x == y && z < x) {
        printf("Middle: %d\n", y);
    }
    if (z == y && z > x) {
        printf("Middle: %d\n", z);
    }
    if (x == z && y > x) {
        printf("Middle: %d\n", x);
    }
    if (x == z && y < x) {
        printf("Middle: %d\n", z);
    }
    if (z == y && z < x) {
        printf("Middle: %d\n", y);
    }
    if (x == y && x == z) {
        printf("Middle: %d\n", z);
    }
    return 0;
}
