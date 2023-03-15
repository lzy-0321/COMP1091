//z5340468
//18/5/2021
//Word Addition

#include <stdio.h>
#include <math.h>
int main(void) {
    
    int z ,a, b, c, d, e, f, g, h, i, k, l, m, n, j, p;
    
    printf("Enter year:");
    scanf("%d", &z);
    a = z%19;
    b = z/100;
    c = z%100;
    d = b/4;
    e = b%4;
    f = (b + 8)/25;
    g = (b - f +1)/3;
    h = (19* a + b - d - g +15)%30;
    i = c/4;
    k = c%4;
    l = (32+2* e +2* i - h - k )%7;
    m =(a +11* h +22* l )/451;
    n = (h + l-7* m +114)/31;
    p =(h + l -7* m +114)%31;
    j = p + 1;
    
    if (n == 3) {
    printf("Easter is March %d in %d. \n", j, z);
    }
    else if (n == 4) {
    printf("Easter is April %d in %d. \n", j, z);
    }
    return 0;
}    
