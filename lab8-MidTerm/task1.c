#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new element at the end of the linked list
void sll_insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to check if a linked list is a palindrome using a stack
bool isPalindrome(struct Node* head) {
    if (head == NULL)
        return true;

    // Create a stack to store elements
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* stack = NULL;

    // Push the first half of the linked list onto the stack
    while (fast != NULL && fast->next != NULL) {
        sll_insert(&stack, slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the linked list has an odd number of elements, skip the middle element
    if (fast != NULL)
        slow = slow->next;

    // Compare the remaining elements with the elements popped from the stack
    while (slow != NULL) {
        if (slow->data != stack->data)
            return false;
        slow = slow->next;
        stack = stack->next;
    }

    return true;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    sll_insert(&head, 1);
    sll_insert(&head, 2);
    sll_insert(&head, 3);
    sll_insert(&head, 2);
    sll_insert(&head, 1);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head))
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}

