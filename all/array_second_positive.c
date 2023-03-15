//1/6/2021
//z5340468
//Find the Second Positive Value in an Array of Integers

#include <stdio.h>

#define NOT_POSITIVE_ENOUGH 0

int array_second_positive(int size, int array[size]) {
    int x = 0;
    int y = 0;
    int z[size];
    while (x < size) {
        if (array[x] > 0) {
            z[y] = 
            array[x];

            y++;
        }
        x++;
    }
    if (y >= 2) {
        return z[1];
    } else {
        return NOT_POSITIVE_ENOUGH;
    }
}    

#define MAX_SIZE 100

int main(void) {
    int size1 = 7;
    int array1[MAX_SIZE] = {3, -14, 15, 9, 2, 6, 5};

    int result1 = array_second_positive(size1, array1);
    if (result1 == NOT_POSITIVE_ENOUGH) {
        printf("array1 wasn't positive enough!\n");
    } else {
        printf("The second positive value from array1 is: %d\n", result1);
    }

    int size2 = 10;
    int array2[MAX_SIZE] = {-1, -2, -4, 8, -16, -32, -64, -128, -256, 512};

    int result2 = array_second_positive(size2, array2);
    if (result2 == NOT_POSITIVE_ENOUGH) {
        printf("array2 wasn't positive enough!\n");
    } else {
      printf("The second positive value from array2 is: %d\n", result2);
    }

    int size3 = 10;
    int array3[MAX_SIZE] = {-1, -3, -4, -8, -16, -33, -64, 138, -356, -513};

    int result3 = array_second_positive(size3, array3);
    if (result3 == NOT_POSITIVE_ENOUGH) {
        printf("array3 wasn't positive enough!\n");
    } else {
      printf("The second positive value from array3 is: %d\n", result3);
    }

    // Note: you can add more tests here (but they won't be marked).

    return 0;
}  
