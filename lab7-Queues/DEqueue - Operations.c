#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct queue *q){
    if (q->r == q->size - 1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if (q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueueFromRear(struct queue *q, int val){
    if (isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeueFromFront(struct queue *q){
    int a = -1;
    if (isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void enqueueFromFront(struct queue *q, int val){
    if (isFull(q)){
        printf("Queue is Full\n");
    }
    else{
        q->arr[q->f] = val;
        q->f--;
        printf("Enqueued element from front: %d\n", val);
    }
}

int dequeueFromRear(struct queue *q){
    int a = -1;
    if (isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        a = q->arr[q->r];
        q->r--;
    }
    return a;
}

int main(){
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 4;
    q->f = 0;
    q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    // Enqueue and dequeue from both ends
    enqueueFromRear(q, 12);
    enqueueFromFront(q, 25);
    enqueueFromRear(q, 15);
    enqueueFromFront(q, 30);
    

    printf("Dequeuing element from front: %d\n", dequeueFromFront(q));
    printf("Dequeuing element from tail: %d\n", dequeueFromRear(q));


    return 0;
}

