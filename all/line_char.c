//14/6/2021
//z5340468
//Line Character

#include <stdio.h>

#define max_size 256

int main(void) {
    int n;
    int i = 0;
    int line[max_size] = {};
    int c = 0; 
    
    while (c != EOF) {
        c = getchar();
        if(c == '\n') {
           scanf("%d", &n);
           printf("The character in position %d is '%c'\n", n, line[n]);
           return 0;
        }
        else if (c == EOF) {
            return 0;
        }   
        else {
            line[i] = c;
            i++;
        }
    }
}

