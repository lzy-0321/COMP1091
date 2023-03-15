//1/6/2021
//z5340468
//Print out pi to a certain number of digits

#include <stdio.h>

#define MAX_DIGITS 10

int main(void) {
    int pi[MAX_DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int x, i;
    i = 1;
    printf("How many digits of pi would you like to print? ");
    scanf("%d", &x);
    if (x == 0) {
        printf("\n");
    }
    if (x == 1) {
        printf("%d\n", pi[0]);
    }
    if (x > 1) {
        printf("%d.", pi[0]);
            while (i < x) {
                printf("%d", pi[i]);
                i = i + 1;
            }
            printf("\n");
    }
    return 0;
}                
