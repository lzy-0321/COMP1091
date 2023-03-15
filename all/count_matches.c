//22/7/21
//z5340468
//Count the times a match happens between two lists

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int countMatches(struct node *head1, struct node *head2);
struct node *stringsToList(int len, char *strings[]);

int main(int argc, char *argv[]) {
    // create two linked lists from command line arguments
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    struct node *head1 = stringsToList(dash_arg - 1, &argv[1]);
    struct node *head2 = stringsToList(argc - dash_arg - 1, &argv[dash_arg + 1]);

    int result = countMatches(head1, head2);
    printf("%d\n", result);

    return 0;
}

// Return a count of how many times two lists have the same value
// in the same position.

int countMatches(struct node *head1, struct node *head2) {
    struct node *current1 = head1;
    struct node *current2 = head2;

    int count = 0;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data == current2->data) {
            count++;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    
    return count;
}


// create linked list from array of strings
struct node *stringsToList(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}

