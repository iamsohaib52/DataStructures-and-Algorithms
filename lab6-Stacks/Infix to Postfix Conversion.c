#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int size;
	int top;
	char *arr;
};
char stackTop(struct stack *sp){
	return sp->arr[sp->top];
}
int isEmpty(struct stack *sp){
	if(sp->top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isFull(struct stack *sp){
	if(sp->top==sp->size-1){
		return 1;
	}
	else{
		return 0;
	}
}
void push(struct stack *sp, char val){
	if(isFull(sp)){
		printf("Stack Overflow, Cannot Push %c into Stack\n", val);
	}
	else{
		sp->top++;
		sp->arr[sp->top]=val;
	}
}
char pop(struct stack *sp){
	char a=-1;
	if(isEmpty(sp)){
		printf("Stack Underflow, Nothing to Pop\n");
	}
	else{
		a=sp->arr[sp->top];
		sp->top--;
	}
	return a;
}
int isOperator(char ch){
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
		return 1;
	}
	else{
		return 0;
	}
}
int precedence(char ch){
	if(ch=='^'){
		return 4;
	}
	else if(ch=='*' || ch=='/'){
		return 3;
	}
	else if(ch=='+' || ch=='-'){
		return 2;
	}
	else{
		return 0;
	}
}
char* infixToPostfix(char* infix){
	struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
	sp->size=10;
	sp->top=-1;
	sp->arr=(char*)malloc(sp->size*sizeof(char));
	char *postfix=(char*)malloc((strlen(infix)+1) * sizeof(char));
	int i=0;
	int j=0;
	while(infix[i]!='\0'){
		if(!isOperator(infix[i])){
			postfix[j]=infix[i];
			j++;
			i++;
		}
		else{
			if(precedence(infix[i])>precedence(stackTop(sp))){
				push(sp, infix[i]);
				i++;
			}
			else{
				postfix[j]=pop(sp);
				j++;
			}
		}
	}
	while(!isEmpty(sp)){
		postfix[j]=pop(sp);
		j++;
	}
	postfix[j]='\0';
	return postfix; 
}
int main(){
	char *infix="x-y/z-k*d";
	printf("PostFix: %s", infixToPostfix(infix));
	return 0;
}
