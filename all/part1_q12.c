#include <stdio.h>

int main(void) {
    int array[3];
    int *p1 = &array[2];
    int *p2 = NULL;
    int *p3 = p2;
    *p1 = 7;
    *p2 = 2;
    *p3 = *p1 + *p2;
}
