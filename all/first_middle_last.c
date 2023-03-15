//8/6/2021
//z5340468
//First Middle Last

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

void print_first_middle_last(int size, int array[MAX_LENGTH]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // Get the array size.
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);

    // Declare the array.
    int array[MAX_LENGTH];

    printf("Enter array values: ");
    // Initialise the array values.
    int i = 0;
    while (i < size) {
        scanf("%d", &array[i]);
        i = i + 1;
    }

    print_first_middle_last(size, array);

    return 0;
}

// Print the first, middle, and last values of an array,
// on separate lines.
void print_first_middle_last(int size, int array[MAX_LENGTH]) {
    int m = 0;
    while (m <= size) {
        if (m == 0) {
            printf("%d\n", array[m]);
            
        }
        if (m == (size + 2)/2 ) {
            printf("%d\n", array[m-1]);
        }
        if (m == size) {
            printf("%d\n", array[size - 1]);
        }
        m++;
    }
}
