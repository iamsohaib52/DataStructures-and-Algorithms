#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev; // Add a pointer to the previous node
};

void doublyLinkedListTraversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
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
    head->prev = NULL; // The previous pointer of the head node should be NULL

    second->data = 9;
    second->next = third;
    second->prev = head; // Point the previous pointer of the second node to the head node

    third->data = 11;
    third->next = fourth;
    third->prev = second; // Point the previous pointer of the third node to the second node

    fourth->data = 13;
    fourth->next = NULL;
    fourth->prev = third; // Point the previous pointer of the fourth node to the third node

    doublyLinkedListTraversal(head);
    return 0;
}

