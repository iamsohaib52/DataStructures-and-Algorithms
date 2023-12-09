#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* newnode = new Node;
    newnode->data = x;
    newnode->next = NULL;
    if (rear == NULL) {
        front = rear = newnode;
        rear->next = front;
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue() {
    Node* temp = front;
    if (front == NULL && rear == NULL) {
        cout << "\nQueue is empty";
    } else if (front == rear) {
        front = rear = NULL;
        delete temp;
    } else {
        front = front->next;
        rear->next = front;
        delete temp;
    }
}

int peek() {
    if (front == NULL && rear == NULL) {
        cout << "\nQueue is empty";
        return -1;
    } else {
        cout << "\nThe front element is " << front->data;
        return front->data;
    }
}

void display() {
    Node* temp = front;
    cout << "\nThe elements in a Queue are: ";
    if (front == NULL && rear == NULL) {
        cout << "Queue is empty";
    } else {
        while (temp->next != front) {
            cout << temp->data << ",";
            temp = temp->next;
        }
        cout << temp->data;
    }
}

int main() {
    enqueue(14);
    enqueue(11);
    enqueue(13);
    display();
    dequeue();
    display();
    peek();
    return 0;
}
