//1/10/2021
//z5340468
//Print an Hourglass

#include <stdio.h>

int main(void) {
    int num;
    printf("Please enter a size: ");
    scanf("%d", &num);
    if (num > 2 && num % 2 == 1) {
        int x = 0;
        int y = 0;   
        while (x < num) {
            printf("-");
            x++;
        }
        printf("\n");
        x = 0;
        y++;
        int n = 1;
        int half;
        int print = 0;
        half = (num - 1) / 2;
        while (y <= half) {
            while (x < num) {
                while (print < n) {
                    printf("-");
                    x++;
                    print++;
                }
                while (x < (num - n)) {
                    printf("%d", n);
                    x++;
                }
                while (x < num) {
                    printf("-");
                    x++;
                }
            }
            print = 0;
            x = 0;
            y++;
            n++;
            printf("\n");
            
        }
        n = n - 2;
        while (y < num - 1) {
            while (print < n) {
                    printf("-");
                    x++;
                    print++;
                }
                while (x < (num - n)) {
                    printf("%d", n);
                    x++;
                }
                while (x < num) {
                    printf("-");
                    x++;
                }
            print = 0;
            x = 0;
            y++;
            n--;
            printf("\n");
        }
        while (x < num) {
            printf("-");
            x++;
        }
        printf("\n");   
    }
    return 0;
}
