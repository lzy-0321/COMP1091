//z5340468
//18/05/2021
//Numbers to Words

#include <stdio.h>

int main(void) {
    
    int x;
    
    printf("Please enter an integer: ");
    scanf("%d", &x);
     
     
    if (x < 1) {
        printf("You entered a number less than one.\n");
    } 
    if (x > 5) {
        printf("You entered a number greater than five.\n");
    } 
    if (x == 1) {
        printf("You entered one. \n");
    }
    if (x == 2) {
        printf("You entered two. \n");
    }
    if (x == 3) {
        printf("You entered three. \n");
    }
    if (x == 4) {
        printf("You entered four. \n");
    }
    if (x == 5) {
        printf("You entered five. \n");
    } 
    return 0;
}    
