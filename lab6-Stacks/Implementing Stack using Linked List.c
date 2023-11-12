#include<stdio.h>
#include<stdlib.h>
struct node *top=NULL;    //Declaring Top as global variable to avoid ambiguity
struct node{
	int data;
	struct node *next;
};
void traversal(struct node *ptr){
	printf("Elements in Linked List are: ");
	while(ptr!=NULL){
		printf("%d  ", ptr->data);
		ptr=ptr->next;
	}
}
int isEmpty(struct node *top){
	if(top==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
int isFull(struct node *top){
	struct node *n=(struct node*)malloc(sizeof(struct node));
	if(n==NULL){
		return 1;
	}
	else{
		return 0;
	}
}
struct node *push(struct node *top, int val){
	if(isFull(top)){
		printf("Stack Overflow, Cannot push %d into Stack\n", val);	
	}
	else{
		struct node *newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=val;
		newnode->next=top;
		top=newnode;
		return top;
	}
}
int pop(struct node *t){
	if(isEmpty(t)){
		printf("Stack Underflow, Nothing to Pop -> Error: ");
		return -1;
	}
	else{
		struct node *n=t;
		t=t->next;
		int x=n->data;
		free(n);
		return x;
	}
}
int peek(int position){
	struct node *ptr=top;
	int i;
	for(i=0; (i<(position-1) && ptr!=NULL); i++){
		ptr=ptr->next;
	}
	if(ptr!=NULL){
		return ptr->data;
	}
	else{
		return -1;
	}
}
void stackBottom(){
    if(isEmpty(top)){
        printf("Stack Underflow!\n");
    }
    else{
        struct node* ptr = top;
        while(ptr->next != NULL){
        ptr = ptr->next;
        }
        printf("\nBottom-most Element of Stack is %d\n",ptr->data);
    }
}
int stackTop(){
	return top->data;
}
int main(){
	top=push(top, 5);
	top=push(top, 7);
	top=push(top, 9);
	top=push(top, 11);
	top=push(top, 15);
	traversal(top);
	
	//	int p=pop(top);
	//	printf("\nPopped Element is: %d", p);
	
	int i;
	for(i=1; i<=5; i++){
		printf("\nValue at Position %d is: %d", i, peek(i));
	}
	printf("\nTop-most Element of Stack is: %d", stackTop());
	stackBottom();
	return 0;
}
