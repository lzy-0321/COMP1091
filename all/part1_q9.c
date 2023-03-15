#include <stdio.h>
int main(void) {
    int array[5] = {4, 3, 0, -7, -3};
    int i = 0;
    int sum = 0;
    while (i < 5) {
        sum = sum + array[i];
        printf("%d\n", sum);

        i++;
    }
   return 0;
}
