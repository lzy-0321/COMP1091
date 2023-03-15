#include<stdio.h>

int main() {
    int ch;
    int n = 0;
    while ((ch = getchar()) != EOF) {
        if (ch >= '0' && ch <= '9')
        n++;
    }
    printf("%d digits.\n", n);
    return 0;    
 }

