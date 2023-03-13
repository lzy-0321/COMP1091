int check(struct node *head, int value) {
    while (head != NULL) {
        if (head->data == value) {
            return 0;
        }
        head = head->next;
    }
    return 1;
}