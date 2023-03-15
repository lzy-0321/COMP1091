//12/06/2021
//z5340468
//Find any elements that are the same in two arrays and put them in a third array

// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination
#include <stdio.h>

int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    int x1 = 0,  num = 0;
    while(x1 < length) {
        int x2 = 0, found = 0;
        while (x2 < length) {
            if (source1[x1] == source2[x2]) {
                found = 1;
            }
            x2++;
        }
        if (found) {
            destination[num] = source1[x1];
            num++;
        }
        x1++;
    }
    return num;
}

// You may optionally add a main function to test your common_elements function.
// It will not be marked.

