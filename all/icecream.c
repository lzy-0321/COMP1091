//z5340468
//20/5/2021
//Buying Icecream

#include <stdio.h>

int main(void) {

    int x, y, sum;
    
    printf("How many scoops?  ");
    scanf("%d", &x);
    printf("How many dollars does each scoop cost? ");
    scanf("%d", &y);
    
    sum = x * y;
    
    if (sum <= 10) {
        printf("You have enough money!\n");
    }
    else {
        printf("Oh no, you don't have enough money :(\n");
    }
    
    return 0;
}        
       
