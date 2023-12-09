#include <iostream>

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int data, int priority) {
        this->data = data;
        this->priority = priority;
        this->next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);

        if (isEmpty() || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            while (current->next && priority <= current->next->priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Dequeue operation is not possible." << std::endl;
            return -1;
        } else {
            int data = front->data;
            Node* temp = front;
            front = front->next;
            delete temp;
            return data;
        }
    }

    int peek() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Peek operation is not possible." << std::endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        Node* current = front;
        while (current) {
            std::cout << "Data: " << current->data << ", Priority: " << current->priority << std::endl;
            current = current->next;
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(3, 3);
    pq.enqueue(1, 1);
    pq.enqueue(2, 2);
    pq.enqueue(4, 4);

    std::cout << "Priority Queue Contents:" << std::endl;
    pq.display();

    std::cout << "Dequeuing: " << pq.dequeue() << std::endl;

    std::cout << "Priority Queue Contents after Dequeue:" << std::endl;
    pq.display();

    return 0;
}