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

struct node* deleteAtEnd(struct node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }

    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    }

    free(current);
    return head;
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

    printf("Initial Doubly Linked List: ");
    linkedListTraversal(head);

    head = deleteAtEnd(head);
    printf("\nAfter Deleting the Last Node: ");
    linkedListTraversal(head);

    return 0;
}

