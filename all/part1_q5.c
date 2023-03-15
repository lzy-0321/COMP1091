#include <stdio.h>
#define MIN_RATING 7


int add(int c, int d) {
    c = c + d;
    return d;
}

int main(void) {
    int a = 0; // <--
    int b = 0; // <--
    int c = 0; // <--
    int d = 0; // <--

    a += 2;

    if (a == b) {
        b = 7;
    }

    d = add(c, 7);

    // Which variables will not equal 0 at this point?

    printf(" %d ", a);
    printf(" %d ", b);
    printf(" %d ", c);
    printf(" %d ", d);
    



    return 0;
}
