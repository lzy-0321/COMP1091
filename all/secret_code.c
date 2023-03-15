//22/10/2021
//z5340468
//Solve Tom's Secret Code

#include <stdio.h>
#define max_size 256


int main(void) {
    int i = 0;
    int n = 0;
    int line[max_size] = {};
    int c = 0; 
     while (c != EOF) {
        c = getchar();
        if(c == '\n') {
           while (n <= i) {
               if (line[n] <= line [n+1]) {
                   printf("%c", line[n]);
            }
                else {
                    printf("%c", line[n+1]);
                } 
                n= n+2;
            }
            printf("\n");
        }  
        else {
            line[i] = c;
            i++;
        }
    }

    return 0;
}

