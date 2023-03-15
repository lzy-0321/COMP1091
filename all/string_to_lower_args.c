#include <stdio.h>

#define MAX 100

int main(int argc, char *argv[]) {
    int wordcount = 1;
    while (wordcount < argc) {
        char *word = argv[wordcount];
        int i = 0;
        while (word[i] != '\0') {
            if (word[i] <= 'Z' && 'A' <= word[i]) {
                word[i] = word[i] - 'A' + 'a';
                i++;
            }
            else {
                i++;
            }
        }
        printf(word, stdout);
        printf(" ");
        wordcount++;
    }
    printf("\n");
    return 0;
}
