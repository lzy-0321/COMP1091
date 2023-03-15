//10/6/2021
//z5340468
//Print an e.

#include <stdio.h>

int main(void) {

    int x, y, z;
    
    scanf("%d", &z);
    
    x = 1;
    y = 0;
    
    if (z > 4) {
        if (z % 2 == 1) {
            while (x <= z) {
                if (x == 1) {
                    y = 0;
                    while (y < z) {
                        printf("#");
                        y++;
                    }
                 }
                 else if (x == (z + 1)/ 2) {
                    y = 0;
                    while (y < z) {
                        printf("#");
                        y++;
                    }
                 }
                 else if (x == z) {
                    y = 0;
                    while (y < z) {
                        printf("#");
                        y++;
                    }
                }
                else { printf("#");
                } 
                printf("\n");
                x++;
            }
        }
    
        if (z % 2 == 0) {
            while (x <= z) {
                if (x == 1){
                    while (y < z) {
                        printf("#");
                        y++;
                    }
                }
                else if (x == (z + 2)/ 2 ) {
                    y = 0;
                    while (y < z) {
                        printf("#");
                        y++;
                    }
                }
                else if (x == z) {
                    y = 0;
                    while (y < z) {
                        printf("#");
                        y++;
                    }
                }
                else { printf("#");
                }
                printf("\n");
                x++;
            }
        }
    }    
    return 0;
}
