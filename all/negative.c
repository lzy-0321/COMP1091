//z5340468
//18/5/2021
//Don't be so negative!

#include <stdio.h>
int main(void) {

    int x;
    
    printf(" ");
    scanf("%d", &x);
    if (x == 0) {
        printf("You have entered zero.\n");
    }      
    if (x > 0) {
        printf("You have entered a positive number.\n");
    }
    if (x < 0) {
        printf("Don't be so negative!\n");
    }   
    return 0;
}    
