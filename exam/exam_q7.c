// Exam Question 7
// exam_q7.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// One line summary of what this exercise does.
#include <stdio.h>

#define MAX 6

int check(char x[MAX]);

int main(void) {
    int y = 0;
    char x[MAX];
    while (y < MAX) {
        scanf("%s", &x);
        y++;
    }
    y = 0;
    while (y < 6) {
        if (y = 0) {
            int check = check(x);
            if (check != 0) {
                
            }
        }
    }
    
    return 0;
}

int check(char x[MAX]) {
    int i = 0;
    while (i < 6) {
        if (x[i] != '_') {
            return i;
        }
        i++;
    }
    return 0;
}