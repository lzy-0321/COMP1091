//2/5/2021
//z5340468
//Are You Perfect

#include <stdio.h>

int main(void) {

    int number;
    int factor = 1;
    int sum = 0;
    int test = 0;
        
    printf("Enter number: ");
    scanf("%d", &number);
    
    sum = number;
    
    printf("The factors of %d are:\n", number);
        
    while (factor < number) {
           if ( number % factor == 0) {
               printf("%d\n", factor);
               sum = sum + factor;
           }
           factor = factor + 1;
           
    }
    
    printf("%d\n", number);
    printf("Sum of factors = %d\n", sum);
    test = sum - number;
    
    if (test == number) {
        printf("%d is a perfect number\n", number);
    }
    else {
        printf("%d is not a perfect number\n", number);
    }    
    return 0;
}               
