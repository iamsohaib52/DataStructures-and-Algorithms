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

struct node *insertAtEnd(struct node *head, int val){
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=val;
	struct node *p=head;
	do{
		p=p->next;
	}while(p->next!=head);
	struct node *last=p;
	last->next=newNode;
	newNode->next=head;
	return head;
}

int main() {
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 11;
    third->next = head; // Make it circular by connecting the last node to the head.

    printf("Initial Circular Linked List: ");
    linkedlisttraversal(head);

    printf("\nAfter Inserting a Node at the End: ");
    head = insertAtEnd(head, 57);
    linkedlisttraversal(head);

    return 0;
}

