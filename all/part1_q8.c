#include <stdio.h>
int main(void) {
int i = 0;
int q = 7;
while (q > 0) {
    if (i % 2 == 0) {
        i += 1;
        printf(" %d ", i);
    } else {
        i += 3; 
        printf(" %d ", i);
    }
    q = q - i;
} 
    
   return 0;
}
