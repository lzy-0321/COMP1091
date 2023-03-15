#include <stdio.h>
#include <stdlib.h>

#define MAX  1024

int main(void) {
    int arr[MAX];
    int i = 0;
    scanf("%d", &arr[0]);
    while (arr[i] != 0) {
        i++;
        scanf("%d", &arr[i]);

    }
    if (i % 2 == 0) {
        i = i / 2;
    }
    else { 
        i = (i + 1) / 2;
    }
    int out = 0;
    printf("First Half:");
    while (out < i) {
        printf(" %d", arr[out]);
        out++;
    }
    printf("\n");
    return 0;
}
