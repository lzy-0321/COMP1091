#include <stdio.h>

int differentElements(int length, int source1[length], int source2[length], int destination[length]) {
    int x1 = 0,  num = 0;
    int x2 = 0, found = 0;
    while(x1 < length) {
        
        while (x2 < length) {
            if ((source1[x1] - source2[x2]) != 0) {
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
    int a,z,c,d;
    x1 = 0;
    x2 = 1;
    found = 0;
    while(x1 < length) {
        while (x2 < length) {
            if ((source1[x1] - source1[x2]) != 0) {
                a = x1;
                z = x2;
            }
            x2++;
        }
        x1++;
    }
    x1 = 0;
    x2 = 1;
    found = 0;
    while(x1 < length) {
        while (x2 < length) {
            if ((source2[x1] - source2[x2]) != 0) {
                c = x1;
                d = x2;
            }
            x2++;
        }
        x1++;
    }
    if (a < z || c < d) {
        num = 0;
    }
    if (a > z || c > d) {
        num = 0;
    }
    return num;
}
