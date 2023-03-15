//5/6/2021
//z5340468
//Return How Many Big (Positive and Negative) Numbers are in an Array

#include <stdio.h>


int count_bigger(int length, int array[length]) {
    int n = 0;
    int result = 0;
    while (n < length) {
        if (array[n] > 99 || array[n] < -99) {
            result++;
        }
        n++;
    }    
    return result;
}


#define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {141, 5, 92, 6, 535, -89, -752, -3};

    int result = count_bigger(TEST_ARRAY_SIZE, test_array);

    printf("%d\n", result);
    return 0;
}
