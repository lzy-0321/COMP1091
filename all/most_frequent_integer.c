//z5340468
//3/7/2021
//Find the most frequent integer in an arrayDraw a Danish flag using ASCII characters

#include <stdio.h>

int posOrNext(int needle, int haystack[]) {
    int i = 0;
    while (haystack[i] != 0) {
        if (haystack[i] == needle) return i;
        i++;
    }
    return i;
}

int main(void) {

    int ints[100000] = {0};
    int intsC[100000] = {0};

    int v;
    while (scanf("%d", &v) != EOF) {
        int pos = posOrNext(v, ints);
        ints[pos] = v;
        intsC[pos]++;
    }

    int c = 0;

    int highestInt = -1;
    int highestC = -1;
    while (ints[c] != 0) {
        if (intsC[c] > highestC || (intsC[c] == highestC && ints[c] > highestInt)) {
            highestC = intsC[c];
            highestInt = ints[c];
        }
        c++;
    }
    printf("%d\n", highestInt);
}
