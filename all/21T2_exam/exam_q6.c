// exam_q6.c
//
// This program was written by z5555555
// on INSERT-DATE-HERE

#include <stdio.h>
#include <stdlib.h>

// Do not edit this struct. You may use it exactly as
// it is but you cannot make changes to it

// A node in a linked list
struct node {
    int height;
    struct node *next;
};

// ADD ANY FUNCTION DECLARATIONS YOU WISH TO USE HERE

struct node *mountaineer(struct node *head) {
    // TODO: COMPLETE THIS FUNCTION

    return head;
}


///////////////////////////////////////////////////////////////
//
// YOU DO NOT NEED TO UNDERSTAND CODE BELOW THIS COMMENT
// 
// DO NOT CHANGE CODE BELOW THIS COMMENT
//
// IF YOU THINK YOU NEED TO CHANGE ANYTHING BELOW THIS COMMENT,
// YOU HAVE MISUNDERSTOOD THE QUESTION
//
///////////////////////////////////////////////////////////////

void print_and_free_list(struct node *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    printf("%d, ", head->height);
    print_and_free_list(head->next);
    free(head);
}

struct node *make_list(int length, char *argv[]) {
    struct node *head = malloc(sizeof (struct node));
    struct node *n = head;
    int i = 0;
    while (i < length) {
        n->height = strtol(argv[i + 1], NULL, 10);
        if (i < length - 1) {
            // there are more nodes to make
            n->next = malloc(sizeof (struct node));
            n = n->next;
        } else {
            n->next = NULL;
        }
        i++;
    }
    return head;
}

int main(int argc, char *argv[]) {
    struct node *head = make_list(argc - 1, argv);
    struct node *return_path = mountaineer(head);
    printf("Given stopping points: ");
    print_and_free_list(head);

    printf("Return stopping points: ");
    print_and_free_list(return_path);
    return 0;
}
