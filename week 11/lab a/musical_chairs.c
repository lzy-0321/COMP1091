#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Do not edit these structs. You may use them exactly as
// they are but you cannot make changes to them

// player in the game of chairs
struct player {
    char name[MAX_NAME_LENGTH];
};

// A node in a linked list of chairs
struct chair {
    struct player *sitting;
    struct chair *next;
};

// DECLARE ANY FUNCTIONS YOU WRITE HERE

// Make music for a certain number of turns.
// Each turn of music makes the players move
// one chair along the list.
// After they've moved that many times, the
// first chair in the list is removed, along
// with the person sitting in it.
void move(struct chair *chairs) {
    struct chair *c = chairs;
    struct player *players = NULL;
    while (c != NULL) {
        struct player *moving = c->sitting;
        c->sitting = players;
        players = moving;
        c= c->next;
    }
    if (chairs != NULL) {
        chairs->sitting = players;
    }
}

struct chair *make_music(int turns, struct chair *chairs) {
    int i = 0;
    while (i < turns - 1) {
        move(chairs);
        i++;
    }
    struct chair *delete = chairs->next;
    printf("%s\n", delete->sitting->name);
    chairs->next = chairs->next->next;
    free(delete->sitting);
    free(delete);
    move(chairs);
    return chairs;
}

// This helper function is only for this main, but
// it may help you to both understand and test this exercise.
// You may use this function for testing, but
// YOU CANNOT CHANGE THIS FUNCTION
struct chair *be_seated(char name[MAX_NAME_LENGTH], struct chair *heir) {
    struct chair *c = malloc(sizeof(struct chair));
    c->sitting = malloc(sizeof(struct player));
    strcpy(c->sitting->name, name);
    c->next = heir;
    return c;
}

// This is a main function which could be used
// to test your make_music function.
// It will not be marked.
// Only your make_music function will be marked.
int main(int argc, char * argv[]) {
    struct chair *thrones = be_seated("Robert Baratheon", NULL);
    thrones = be_seated("Cersei Lannister", thrones);
    thrones = be_seated("Joffrey Baratheon", thrones);
    thrones = be_seated("Eddard Stark", thrones);
    thrones = be_seated("Spoiler Alert", thrones);
        
    thrones = make_music(1, thrones);
    thrones = make_music(3, thrones);
    thrones = make_music(0, thrones);
    thrones = make_music(2, thrones);

    free(thrones->sitting);
    free(thrones);
        
    return 0;
}

// DEFINE ANY FUNCTIONS YOU WRITE HERE

