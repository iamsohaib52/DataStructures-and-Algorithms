#include <stdio.h>
#include <stdlib.h>
 
struct stack{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr){
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if (ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int parenthesisMatch(char *input){
	struct stack *sp;
	sp->size=10;
	sp->top=-1;
	sp->arr=(char*)malloc(sp->size*sizeof(char));
	int i;
	for(i=0; input[i]!='\0'; i++){
		if(input[i]=='('){
			push(sp, '(');
		}
		else if(input[i]==')'){
			if(isEmpty(sp)){
				return 0;
			}
			pop(sp);
		}
	}
	if(isEmpty(sp)){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	char *input="((8)(*--$$9))";
	if(parenthesisMatch(input)){
		printf("Parenthesis is Matching.");
	}
	else{
		printf("Parenthesis is Not Matching.");
	}
	
	return 0;
}

