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

struct node *deleteNodeWithValue(struct node *head, int value) {
    if (head == NULL) {
        printf("Circular Linked List is empty\n");
        return head;
    }

    struct node *current = head;
    struct node *previous = NULL;

    do {
        if (current->data == value) {
            if (previous == NULL) {
                // If the value to delete is in the head node.
                struct node *last = head;
                do {
                    last = last->next;
                } while (last->next != head);

                last->next = head->next;
                free(head);
                return last->next;
            } else {
                previous->next = current->next;
                free(current);
                return head;
            }
        }

        previous = current;
        current = current->next;
    } while (current != head);

    printf("\nValue Not Found in the Linked List");
    return head;
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

    head = deleteNodeWithValue(head, 11);
    printf("\nAfter Deleting a node with a specific value: ");
    linkedlisttraversal(head);

    return 0;
}

