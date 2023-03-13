#include <stdio.h>

#define MAX_length 4096

int main(void) {
    char input[MAX_length];
    int num = 0;
    printf("Enter a string: ");
    fgets(input, MAX_length, stdin);
    while (input[num] != '\0' && input[num] != '\n') {
        num++;
    }
    int check = 0;
    int right = num - 1;
    int left = 0;
    while (left <= right) {
        if (input[left] != input[right]) {
            check++;
        }
        left++;
        right--;
        
    }
    if (check == 0) {
        printf("String is a palindrome\n");
    }
    else {
        printf("String is not a palindrome\n");
    }
    return 0;
}

