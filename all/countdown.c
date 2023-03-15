//25/5/2021
//z5340468
//Count From 10 to 0 With a Loop

#include <stdio.h>

int main(void) {
    
    int counter1 = 10; 
    int counter2 = 1;
    
    while (counter2 <= 11) {
           printf("%d\n", counter1);
           counter1 = counter1 - 1;
           counter2 = counter2 + 1;
    }
    return 0;
}           
