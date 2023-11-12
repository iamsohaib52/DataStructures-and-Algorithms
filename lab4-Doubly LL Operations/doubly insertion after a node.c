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

struct node* insertAfterNode(struct node* head, struct node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return head;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    
    newNode->next = prevNode->next;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
    
    newNode->prev = prevNode;
    prevNode->next = newNode;
    
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

    head = insertAfterNode(head, second, 57);
    printf("\nAfter inserting 57 after the second node: ");
    linkedListTraversal(head);

    return 0;
}

