#include <stdio.h>
int main() {
    int num, sum = 0;

    while (1) {
        scanf("%d", &num);
        if (num < 0) {
            break;
        }
        else {
            sum = sum + num;
       }
    }
    printf("Sum of odd numbers was: %d\n", sum);
    return 0;
}
