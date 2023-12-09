#include <iostream>
#include<stack>
using namespace std;

int queue[5],N=5;
int front = -1;
int rear = -1;

void enqueue(int x) {
    if ((rear + 1) % N == front) {
        cout << "Queue is full" <<endl;
    } else {
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % N;
        }
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty" << std::endl;
    } else if (front == rear) {
        cout << "Dequeued element: " << queue[front] << std::endl;
        front = rear = -1;
    } else {
        cout << "Dequeued element: " << queue[front] << std::endl;
        front = (front + 1) % N;
    }
}

void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        cout << "Queue is empty" << std::endl;
    } else {
        cout << "Queue elements: ";
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % N;
        }
        cout << queue[rear] << std::endl;
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    return 0;
}

