//2/5/2021
//z5340468
//Draw a Hollow Triangle

#include <stdio.h>

int main(void) {
     
    int x;
    int i = 1;
    
    
    printf("Enter size: ");
    scanf("%d", &x);
    
    while (i <= x) {
        
        int c = 1;
        
        while (c <= i) {
            if ((c == 1 || c == i) && i < x) {
                printf("*");
            }
            if (c != 1 && c != i && i < x) {
                printf(" ");
            }
            if (i == x && c <= i) {
                printf("*");
            }
            c = c + 1;
        }
        printf("\n");
        i = i + 1;
    }

    return 0;
}
