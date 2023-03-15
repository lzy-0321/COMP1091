#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int upper(int character);
int lower(int character);
int swap(int character);

int main(int argc, char *argv[]) {

    int character = getchar();
    
    if (strcmp(argv[1], "--upper") == 0) {
        while (character != EOF) {
            int upper_character = upper(character);
            putchar(upper_character);
            character = getchar();
        }
    }
    else if (strcmp(argv[1], "--lower") == 0) {
        while (character != EOF) {
            int lower_character = lower(character);
            putchar(lower_character);
            character = getchar();
        }
    }
    else if (strcmp(argv[1],"--swap") == 0) {
        while (character != EOF) {
            int swap_character = swap(character);
            putchar(swap_character);
            character = getchar();
        }
    }
    else if (argv[1] == NULL) {
        while (character != EOF) {
            putchar(character);
            character = getchar();
        }
    }
    return 0;
}

int upper(int character) {
      if (character >= 'a' && character <= 'z') {
        return character - 32;
    } else {
        return character;
    }
}

int lower(int character) {
      if (character >= 'A' && character <= 'Z') {
        return character + 32;
    } else {
        return character;
    }
}

int swap(int character) {
      if (character >= 'A' && character <= 'Z') {
        return character + 32;
    } else if (character >= 'a' && character <= 'z') {
        return character - 32;
    } else {
        return character;
    }
}
