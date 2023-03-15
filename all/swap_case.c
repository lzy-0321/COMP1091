//14/6/2021
//z5340468
//Its a Case of Swapping

#include <stdio.h>
#include <stdlib.h>

int swap_case(int character);

int main(int argc, char *argv[]) {
    int character = getchar();
    while (character != EOF) {
        int swapped_character = swap_case(character);
        putchar(swapped_character);
        character = getchar();
    }

    return 0;
}


int swap_case(int character) {
    if (character >= 'A' && character <= 'Z') {
        return 'a' + character - 'A';
    } else if (character >= 'a' && character <= 'z') {
        return 'A' + character - 'a';
    } else {
        return character;
    }
}
