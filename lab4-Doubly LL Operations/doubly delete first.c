#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void linkedListTraversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
}

struct node* deleteFirst(struct node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }

    struct node* newHead = head->next;
    if (newHead != NULL) {
        newHead->prev = NULL;
    }

    free(head);
    return newHead;
}

int main() {
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    head->prev = NULL;

    second->data = 9;
    second->next = third;
    second->prev = head;

    third->data = 11;
    third->next = fourth;
    third->prev = second;

    fourth->data = 13;
    fourth->next = NULL;
    fourth->prev = third;

    printf("Initial Doubly Linked List is: ");
    linkedListTraversal(head);

    head = deleteFirst(head);

    printf("\nAfter Deleting the first element: ");
    linkedListTraversal(head);

    return 0;
}

