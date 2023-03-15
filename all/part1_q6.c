#include <stdio.h>


void swap(char num_1, char num_2) {
    double tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    
}

int main(void) {
    double num_1 = 2.0;
    double num_2 = 3.0;
    swap(&num_1, &num_2);

    printf("%lf and %lf\n", num_1, num_2);
}
