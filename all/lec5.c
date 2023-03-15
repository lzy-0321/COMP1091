#include <stdio.h>
int main (void) {
    int sum = 0;
    int number;
    int numberRead = 1;
    printf("\n");
    while (numberRead == 1) {
           numberRead = scanf("%d", &number);
           if (numberRead == 1) {
              sum = sum + number;
           }   
    }
    printf("%d\n", sum);       
    return 0;
}    
