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

struct node *deleteAtIndex(struct node *head, int index){
	struct node *p=head;
	struct node *q=head->next;
	int i;
	
	for(i=0; i<index-1; i++){
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);
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

    head = deleteAtIndex(head, 2);
    printf("\nAfter Deleting a node at a specific index: ");
    linkedlisttraversal(head);

    return 0;
}

