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

struct node* deleteAtIndex(struct node* head, int index) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }

    if (index == 0) {
        // Deleting the first node
        struct node* newHead = head->next;
        if (newHead != NULL) {
            newHead->prev = NULL;
        }
        free(head);
        return newHead;
    }

    struct node* current = head;
    int i = 0;

    while (i < index && current != NULL) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Invalid index. Node not deleted.\n");
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
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

    head = deleteAtIndex(head, 2);
    printf("\nAfter Deleting a Node at Specific Index (Index 2): ");
    linkedListTraversal(head);

    return 0;
}

