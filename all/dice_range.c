//z5340468
//18/5/2021
//Dice Range

#include <stdio.h>
#include <math.h>
int main (void) {
    
    int x, y, z;
    float s, p;
    
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &x);
    printf("Enter the number of dice being rolled:  ");
    scanf("%d", &y);
    
    z = x * y;
    
    s = y + z;
    
    p = s / 2;
    
    if (x > 0)  {
        if (y > 0) {
            printf("Your dice range is %d to %d. \n", y, z);
            printf("The average value is %lf \n", p);
        }
        else if (y <= 0) {
            printf("These dice will not produce a range. \n");
        }
    }
    else if (x <= 0 ) {
        printf("These dice will not produce a range. \n");
    }         
    return 0;
} 
