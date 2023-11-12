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

struct node* deleteNodeWithValue(struct node* head, int value) {
    struct node* current = head;
    
    // Search for the node with the given value
    while (current != NULL) {
        if (current->data == value) {
            // If the node is found, update the previous node's next pointer
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            
            // If the node is not the first node, update the next node's prev pointer
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            
            // If the node is the head, update the head pointer
            if (head == current) {
                head = current->next;
            }
            
            free(current); // Free the memory of the deleted node
            return head;
        }
        
        current = current->next;
    }
    
    // If the value is not found, print a message
    printf("\nValue not found in the linked list.");
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

    head = deleteNodeWithValue(head, 11);
    printf("\nAfter Deleting a node with value 11: ");
    linkedListTraversal(head);

    return 0;
}

