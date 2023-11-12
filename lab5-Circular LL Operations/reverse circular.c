#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node *head) {
    struct node *ptr = head;

    if (head == NULL) {
        printf("Empty Circular Linked List\n");
        return;
    }

    do {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *reverse(struct node *head) {
    if (head == NULL) {
        printf("Circular Linked List is empty\n");
        return head;
    }
    struct node *current = head;
    struct node *nextNode;
    struct node *prevNode = NULL;
    do {
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    } while (current != head);

    head->next = prevNode; // Update the head's next to the last node.
    return prevNode;
}

int main() {
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 11;
    third->next = fourth;

    fourth->data = 13;
    fourth->next = head; // Make it circular by connecting the last node to the head.

    printf("Initial Circular Linked List: ");
    linkedlisttraversal(head);

    head = reverse(head);
    printf("\nReversed Circular Linked List: ");
    linkedlisttraversal(head);

    return 0;
}

