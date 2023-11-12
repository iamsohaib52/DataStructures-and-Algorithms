#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
void linkedlisttraversal(struct node *ptr){
	while(ptr!=NULL){
		printf("%d, ", ptr->data);
		ptr=ptr->next;
	}
}
struct node * reverse(struct node *head){
	struct node *prevPtr=NULL;
	struct node *currPtr=head;
	struct node *nextPtr;
	while(currPtr!=NULL){
		nextPtr=currPtr->next;
		currPtr->next=prevPtr;
		
		prevPtr=currPtr;
		currPtr=nextPtr;
	}
	return prevPtr;
}
int main(){
	struct node *head;
	struct node *second;
	struct node *third;
	struct node *fourth;
	
	head=(struct node*) malloc(sizeof(struct node));
	second=(struct node*) malloc(sizeof(struct node));
	third=(struct node*) malloc(sizeof(struct node));
	fourth=(struct node*) malloc(sizeof(struct node));
	
	head->data=7;
	head->next=second;
	
	second->data=9;
	second->next=third;
	
	third->data=11;
	third->next=fourth;
	
	fourth->data=13;
	fourth->next=NULL;
	
	printf("Initial Linked List: ");
	linkedlisttraversal(head);
	
	head=reverse(head);
	printf("\nReversed Linked List: ");
	linkedlisttraversal(head);
	return 0;
}
