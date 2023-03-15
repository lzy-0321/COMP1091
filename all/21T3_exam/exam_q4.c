#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_before(int value, struct node *head);
struct node *create_node(int data, struct node *next);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);
int check(struct node *head, int value);

// Delete the node immediately before the first instance of the
// given `value`.
struct node *delete_before(int value, struct node *head) {
    struct node *n = head;
    if (head == NULL) {
        return NULL;
    }
    int i = check(head, value);
    if (i == 1) {
        return head;
    }
    else if (head->next == NULL) {
        return head;
    }
    else if (head->next->next == NULL) {
        return head;
    }
    else if (head->data == value) {
        return head;
    }
    else if (head->next->data == value) {
        struct node *delete = head;
        head = head->next;
        free(delete);
        return head;
    }
    else {
        while (n->next != NULL) {
            if (n->next->next->data == value) {
                struct node *delete = n->next;
                n->next = n->next->next;
                free(delete);
                return head;
            }
            n = n->next;
        }
    return NULL;
    }
}

int check(struct node *head, int value) {
    while (head != NULL) {
        if (head->data == value) {
            return 0;
        }
        head = head->next;
    }
    return 1;
}
//
// DO NOT CHANGE ANYTHING BELOW THIS COMMENT
//

int main(int argc, char *argv[]) {
    int value;
    scanf("%d", &value);
    // create linked list from command line arguments
    struct node *head = NULL;
    if (argc > 1) {
        // list has elements
        head = strings_to_list(argc - 1, &argv[1]);
    }

    struct node *new_head = delete_before(value, head);
    print_list(new_head);

    return 0;
}


// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }   
    return head;
}

// print linked list
void print_list(struct node *head) {
    printf("[");    
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}
