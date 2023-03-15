//2/5/2021
//z5340468
//Three or Five

#include <stdio.h>

int main(void) {

    int number;
    int output = 1;
    
    printf("Enter number: ");
    scanf("%d", &number);
    
    while (output < number) {           
           if (output % 3 == 0) {
               printf("%d\n", output);
           }
           else if (output % 5 == 0) {
               printf("%d\n", output);
           }    
           output = output + 1;
    }
    return 0;
}           
