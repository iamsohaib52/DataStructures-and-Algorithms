#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

char stackTop(struct stack *sp) {
    return sp->arr[sp->top];
}

int isEmpty(struct stack *sp) {
    return (sp->top == -1);
}

int isFull(struct stack *sp) {
    return (sp->top == sp->size - 1);
}

void push(struct stack *sp, char val) {
    if (isFull(sp)) {
        printf("Stack Overflow, Cannot Push %c into Stack\n", val);
    } else {
        sp->top++;
        sp->arr[sp->top] = val;
    }
}

char pop(struct stack *sp) {
    char a = -1;
    if (isEmpty(sp)) {
        printf("Stack Underflow, Nothing to Pop\n");
    } else {
        a = sp->arr[sp->top];
        sp->top--;
    }
    return a;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
    if (ch == '^') {
        return 4;
    } else if (ch == '*' || ch == '/') {
        return 3;
    } else if (ch == '+' || ch == '-') {
        return 2;
    } else {
        return 0;
    }
}

void reverseString(char *str) {
    int length = strlen(str);
    
    int i;
    for (i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

char *infixToPrefix(char *infix) {
    reverseString(infix);
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;

    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        } else {
            if (precedence(infix[i]) > precedence(stackTop(sp))) {
                push(sp, infix[i]);
                i++;
            } else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while (!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }

    postfix[j] = '\0';

    reverseString(postfix);

    return postfix;
}

int main() {
    char *infix = "x-y/z-k*d";
    printf("Prefix: %s", infixToPrefix(infix));
    return 0;
}

