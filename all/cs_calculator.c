//1/6/2021
//z5340468
//create a simple calculator reading different nunber of integers

#include <stdio.h> 
int power(int y, int z);

int main(void) {

    int x, y, z;
    
    printf("Enter instruction: ");
    
    while (scanf("%d", &x) != EOF) {
        if (x == 1) {
            scanf("%d", &y);
            printf("%d\n", y * y);
        } 
        else if (x == 2) {
            scanf("%d %d", &y, &z);
            printf("%d\n", power(y, z));
        }
        printf("Enter instruction: ");  
    }
    return 0;
}
int power(int y, int z) {
    int result = 1;
    int n = 0;
    while (n < z) {
        result = result * y;
        n++;
    }
    return result;
}           
