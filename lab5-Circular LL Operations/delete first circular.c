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

struct node *deleteFirst(struct node *head) {
	if(head==NULL){
		printf("Empty List\n");
    	return NULL;
	}
	if(head->next==head){
		free(head);
		return NULL;
	}
	
    struct node *current = head;
    struct node *next = head->next;
	
	while(current->next!=head){
		current=current->next;
	}
	current->next=next;
	free(head);
	return next;
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

    head = deleteFirst(head);
    printf("\nAfter Deleting the first element: ");
    linkedlisttraversal(head);

    return 0;
}

