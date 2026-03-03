#include<stdio.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;


node* insert_begin( node *head, int item) {
    node *newnode;

    newnode = (node*)malloc(sizeof(node));
    newnode->data = item;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
    return head;
}


node* delete_end(node *head) {
    node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    temp = head;

    /* If only one node */
    if (temp->next == NULL) {
        free(temp);
        return NULL;
    }

    /* Traverse to last node */
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);

    return head;
}
