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

struct node* insertAtBegin(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    
    newNode->next = head;
    newNode->prev = NULL;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    
    return newNode;
}

int main() {
    struct node* head;
    struct node* second;
    struct node* third;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;
    head->prev = NULL;

    second->data = 9;
    second->next = third;
    second->prev = head;

    third->data = 11;
    third->next = NULL;
    third->prev = second;

    printf("Initial Doubly Linked List: ");
    linkedListTraversal(head);

    head = insertAtBegin(head, 57);
    printf("\nAfter Inserting a Node at the Beginning: ");
    linkedListTraversal(head);

    return 0;
}

