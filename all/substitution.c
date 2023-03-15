//14/6/2021
//z5340468
//Encrypting Text with a Substitution Cipher

#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE  26

int encrypt(int character, char mapping[ALPHABET_SIZE]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <mapping>\n", argv[0]);
        return 1;
    }

    if (strlen(argv[1]) != ALPHABET_SIZE) {
        printf("%s: mapping must contain %d letters\n", argv[0], ALPHABET_SIZE);
        return 1;
    }

    int character = getchar();
    
    while (character != EOF) {
        int encrypted_character = encrypt(character, argv[1]);
        putchar(encrypted_character);
        character = getchar();
    }

    return 0;
}

int encrypt(int character, char mapping[ALPHABET_SIZE]) {
    if (character >= 'A' && character <= 'Z') {
        return mapping[character - 'A'] - 'a' + 'A';
    } 
    else if (character >= 'a' && character <= 'z') {
        return mapping[character - 'a'];
    } 
    else {
        return character;
    }
}

