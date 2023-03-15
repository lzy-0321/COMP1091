#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createList() {
    struct node *list = malloc(sizeof(struct node));

    list->data = 0;
    list->next = malloc(sizeof(struct node));

    list = malloc(sizeof(struct node));

    list->data = 0;
    list->next = NULL;

    return list;
}

int main(void) {
    struct node *list = createList();
    list = list->next;
    free(list);
}
