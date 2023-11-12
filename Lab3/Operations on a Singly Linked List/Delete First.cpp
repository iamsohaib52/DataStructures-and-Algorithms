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
struct node *deletefirst(struct node *head){
	struct node *p=head;
	head=head->next;
	free(p);
	return head;
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
	
	printf("Initial Linked List is: ");
	linkedlisttraversal(head);
	
	head=deletefirst(head);
	
/*  head=deletefirst(head);
	head=deletefirst(head);*    - 2 bar call  karna sy 1st 2 remove honga*/
	
	printf("\nAfter Deleting the first element: ");
	linkedlisttraversal(head);
	return 0;
}
