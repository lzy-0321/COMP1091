//z5340468
//18/05/2021
//Leap Year Calculator

#include <stdio.h> 

int main(void) {
    
    int x;
    printf("Enter year: ");
    scanf("%d", &x);
    
    if (x % 4) {
        printf("%d is not a leap year.\n", x );
    }
    else if (x % 100) {
        printf("%d is a leap year.\n", x );
    }
    else if (x % 400) {
        printf("%d is not a leap year.\n", x );
    }
    else {
        printf("%d is a leap year.\n", x );
    }            
    return 0;
}        
