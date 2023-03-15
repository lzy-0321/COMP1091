//z5340468
//18/05/2021
//Numbers to Words

#include <stdio.h>
int main(void){
    
    int x;
    
    printf(" ");
    scanf("%d", &x);
     
    if (x == 5) {
        printf("You entered five\n");
    }  
    else if (x < 1) {
        printf("You entered a number less than one.\n");
    } 
    else if (x > 5) {
        printf("You entered a number greater than five.\n");
    } 
    else {
        printf("You entered %d \n", x );
    } 
    return 0;
}    
