//22/7/21
//z5340468
//Delete first element greater than a value

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node * deleteGreaterThan(int value, struct node *head);
struct node *stringsToList(int len, char *strings[]);
void printList(struct node *head);
void free_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    if( argc <= 1 ){
        fprintf(stderr,"Insufficient command line arguments\n");
        return EXIT_FAILURE;
    }
    int value = atoi(argv[1]);
    struct node *head = stringsToList(argc - 2, &argv[2]);

    struct node *newHead = deleteGreaterThan(value,head);
    printList(newHead);
    free_list(newHead);
    return EXIT_SUCCESS;
}

// delete the first node in the linked list that has data 
// that is greater than the given value
// if there are no such nodes, then nothing is deleted.
// The function should return the beginning of the resulting list
// The function should call free on the node it deletes. 
struct node *deleteGreaterThan(int value, struct node *head) {
    struct node *a ,*p = head;
     if(head->data > value){
       a = head;
       head = head->next;
       free(a); 
       return head; 
      }
      while(p->next){
      if(p->next->data > value){
      a = p->next;
          p->next = a->next;
       free(a);
       break;
         }
      p=p->next;
  }
      return head;
}


// DO NOT CHANGE THIS FUNCTION

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

// DO NOT CHANGE THIS FUNCTION
// print linked list
void printList(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
         printf("%d", n->data);
         if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

// DO NOT CHANGE THIS FUNCTION
// free linked list
void free_list(struct node *head) {
    if (head != NULL) {
        free_list(head->next);
        free(head);
    }
}
