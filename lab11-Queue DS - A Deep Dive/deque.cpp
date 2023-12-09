#include <iostream>
using namespace std;

int deque[100], n = 100, front = -1, rear = -1;

void insertFront(int val) {
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
        cout << "Deque Overflow" << endl;
    else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0)
            front = n - 1;
        else
            front--;
        deque[front] = val;
    }
}

void insertRear(int val) {
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
        cout << "Deque Overflow" << endl;
    else {
        if (rear == -1) {
            front = 0;
            rear = 0;
        } else if (rear == n - 1)
            rear = 0;
        else
            rear++;
        deque[rear] = val;
    }
}

void deleteFront() {
    if (front == -1)
        cout << "Deque Underflow" << endl;
    else {
        cout << "The deleted element is " << deque[front] << endl;
        if (front == rear)
            front = rear = -1;
        else if (front == n - 1)
            front = 0;
        else
            front++;
    }
}

void deleteRear() {
    if (rear == -1)
        cout << "Deque Underflow" << endl;
    else {
        cout << "The deleted element is " << deque[rear] << endl;
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = n - 1;
        else
            rear--;
    }
}

void display() {
    if (front == -1)
        cout << "Deque is empty" << endl;
    else {
        cout << "Deque elements are:";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << deque[i] << " ";
        } else {
            for (int i = front; i < n; i++)
                cout << deque[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << deque[i] << " ";
        }
    }
}

int main() {
    int ch, val;
    cout << "1) Insert at the front end of Deque" << endl;
    cout << "2) Insert at the rear end of Deque" << endl;
    cout << "3) Delete from the front end of Deque" << endl;
    cout << "4) Delete from the rear end of Deque" << endl;
    cout << "5) Display Deque" << endl;
    cout << "6) Exit" << endl;

    do {
        cout << "Enter choice: " << endl;
        cin >> ch;

        switch(ch) {
            case 1: {
                cout<<"Enter value to be pushed:"<<endl;
                cin>>val;
                insertFront(val);
                break;
            }
            case 2: {
                cout<<"Enter value to be pushed:"<<endl;
                cin>>val;
                insertRear(val);
                break;
            }
            case 3: {
                deleteFront();
                break;
            }
            case 4: {
                deleteRear();
                break;
            }
            case 5: {
                display();
                break;
            }
            case 6: {
                cout<<"Exit"<<endl;
                break;
            }
            default: {
                cout<<"Invalid Choice"<<endl;
            }
        }
    } while(ch != 6);

    return 0;
}