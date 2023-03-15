//2/5/2021
//z5340468
//Draw an X

#include <stdio.h>
int main(void) {
    
    int x, n;
    
    printf("Enter number: ");
    scanf("%d", &n);
    
    x = 2;
    
    while (x < n) {
        if (n % x == 0) { 
